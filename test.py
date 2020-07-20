

# ENUM LinkType
LINK_EDGE = 0
LINK_REVERSE = 1
LINK_NONE = 2


class Save:
    def __init__(self):
        self.link = None
        self.level = 0

class Room:
    def __init__(self, name):
        self.name = name
        self.route = None
        self.save_in = Save()
        self.save_out = Save()

    def __repr__(self):
        desc = ''
        if self.save_in.link:
            desc += f', in = {self.save_in.level}'
        if self.save_out.link:
            desc += f', out = {self.save_out.level}'
        return f'Room("{self.name}"{desc})'


class Link:
    def __init__(self, room1, room2):
        self.type = LINK_EDGE
        self.room1 = room1
        self.room2 = room2

    def __repr__(self):
        type_name = ("LINK_EDGE", "LINK_REVERSE", "LINK_NONE")[self.type]
        return f'Link({type_name}, {self.room1}, {self.room2})'

class App:
    def __init__(self, fn):
        self.rooms = {}
        self.links = []
        self._load(fn)
        assert (self.number > 0)
        assert (self.room_start)
        assert (self.room_end)
        self.paths = []

    def _add_room(self, name, flag_start, flag_end):
        room = Room(name)
        self.rooms[name] = room
        if flag_start:
            self.room_start = room
        if flag_end:
            self.room_end = room
    
    def _add_link(self, name1, name2):
        room1 = self.rooms[name1]
        room2 = self.rooms[name2]
        self.links.append(Link(room1, room2))

    def _load(self, fn):
        iterble = open(fn)
        self.number = int(next(iterble))
        flag_start = flag_end = False
        for line in iterble:
            line = line.strip()
            if line.startswith('#'):
                if line == '##start':
                    flag_start = True
                if line == '##end':
                    flag_end = True
            elif ' ' in line:
                name = line.split(' ')[0]
                self._add_room(name, flag_start, flag_end)
                flag_start = flag_end = False
            elif '-' in line:
                self._add_link(*line.split('-'))



# def calc_bellman_ford(self, debug=False):
    
#     def calc_bellman_ford_clean():
#         for room in self.rooms.values():
#             room.link = None
#             room.level = 0

#     def calc_bellman_ford_update(link, room1, room2, weight):
#         # if debug and "[out] 7" in (room1.name, room2.name):
#         #     print("DEBUG", room1, room2, "weight", weight, room1.link)

#         if room1.link:


#             level = room1.level + weight
#             if debug:
#                 print("DEBUG", room1, room2, "weight", weight, "level", level)
#             if room2.link is None or room2.level > level:
#                 if debug:
#                     print("update")
#                 room2.link = link
#                 room2.level = level
#                 return 1
#         return 0

#     calc_bellman_ford_clean()
#     # open start room
#     self.room_start.link = True

#     index = 0
#     while (index < len(self.links)):
#         count = 0
#         for link in self.links:


#             if link.type == LINK_EDGE:

#                 room1 = link.room1.split if link.room1.flag else link.room1
#                 room2 = link.room2.split if link.room2.flag else link.room2

#                 count += calc_bellman_ford_update(link, room1, link.room2, 1)
#                 count += calc_bellman_ford_update(link, room2, link.room1, 1)

#             elif link.type == LINK_ZERO:
#                 count += calc_bellman_ford_update(link, link.room1, link.room2, 0)
    
#             elif link.type == LINK_REVERSE:
#                 count += calc_bellman_ford_update(link, link.room2, link.room1.split, -1)

#         if count == 0:
#             break
#         index += 1

#     # 
#     print('index', index)
#     print(self.room_end.link)
#     assert(self.room_end.link)
#     print("====")

# def calc_suurballe(self, debug=False):

#     walk = self.room_end
#     while walk != self.room_start:

#         link = walk.link

#         print(walk, "\t", link)

#         if link.type == LINK_EDGE:

#             # swap room for link direction
#             if link.room1 == walk:
#                 link.room1, link.room2 = link.room2, link.room1            
            
#             if link.room1.flag:
#                 walk = link.room1.split
#             else:
#                 link.type = LINK_REVERSE
#                 if link.room1 not in (self.room_start, self.room_end):
#                     link.room1.flag = True
#                 walk = link.room1
            
#         elif link.type == LINK_ZERO:

#             print("LINK_ZERO")
#             walk = link.room1

#         elif link.type == LINK_REVERSE:
            
#             link.type = LINK_NONE
#             link.room1.flag = False
#             # print("!!!!!!!!!!\t", link)
#             print("LINK_REVERSE", link)
#             walk = link.room2

#         elif link.type == LINK_NONE:
#             raise Exception("LINK_NONE")


#     print("====")

# def app_calc(self):

#     calc_bellman_ford(self)
#     calc_suurballe(self)

#     calc_bellman_ford(self)
#     calc_suurballe(self)

#     # calc_bellman_ford(self)
 
#     # for room in self.rooms.values():
#     #     if room.link:
#     #         print(room, room.link)

#     # calc_suurballe(self)

#     print("=======")

#     for link in self.links:
#         if link.type == LINK_EDGE:
            
#             room1 = link.room1.split if link.room1.flag else link.room1
#             room2 = link.room2.split if link.room2.flag else link.room2
#             print(room1.name, '->', link.room2.name, '==', 1)
#             print(room2.name, '->', link.room1.name, '==', 1)
#             pass
#         elif link.type == LINK_REVERSE:
#             print(link.room2.name, '->', link.room1.split.name, '==', -1)
#             pass
#         elif link.type == LINK_ZERO:
#             #print(link)
#             pass
#         elif link.type == LINK_NONE:
#             print(link)
#             pass
#         else:
#             print(link)


def calc_shortest_path(self):

    # CLEAN
    for room in self.rooms.values():
        room.save_in.link = None
        room.save_in.level = 0
        room.save_out.link = None
        room.save_out.level = 0

    # OPEN
    self.room_start.save_in.link = True
    self.room_start.save_out.link = True

    # DO
    index = 0
    while index < len(self.links):
        
        index += 1

        self.update = False

        for link in self.links:
            
            def _update(self, save1, save2, link, weight):
                if save1.link:
                    level = save1.level + weight
                    if not save2.link or save2.level > level:
                        save2.level = level
                        save2.link = link
                        self.update = True
            
            if link.type == LINK_EDGE:
                
                if link.room1.route:
                    _update(self, link.room1.save_out, link.room2.save_in, link, 1)
                else:
                    _update(self, link.room1.save_in, link.room2.save_in, link, 1)

                if link.room2.route:
                    _update(self, link.room2.save_out, link.room1.save_in, link, 1)
                else:
                    _update(self, link.room2.save_in, link.room1.save_in, link, 1)
            
            elif link.type == LINK_REVERSE:
                
                _update(self, link.room1.save_in, link.room2.save_out, link, -1)
                _update(self, link.room2.save_out, link.room2.save_in, link, 0)

            elif link.type == LINK_NONE:
                
                pass

            else:
                raise Exception(link.type)

        if not self.update:
            break

    #print('# index =', index)
    return bool(self.room_end.save_in.link)

def calc_disjoint_path(self):

    room = self.room_end
    
    while room != self.room_start:
        
        link = room.save_in.link
        print(room, link)

        if link.type == LINK_EDGE:
            
            if link.room2 == room:
                link.room1, link.room2 = link.room2, link.room1
            
            link.type = LINK_REVERSE
            if room not in (self.room_start, self.room_end):
                room.route = link.room2
            room = link.room2            
        
        elif link.type == LINK_REVERSE:
            print(room)
            print(link)
            
            # if mode == 2:
            #     print("EDGE")
            #     link.type = LINK_EDGE
            #     print(link)
            #     raise Exception("LINK_REVERSE")
            # else:
            print("NONE")
            link.type = LINK_NONE
            link.room1.route = None
            
            room = link.room1

        else:
            raise Exception("STOP")

    print("EEEE")
    pass


def app_calc(self):
    
    calc_shortest_path(self)
    calc_disjoint_path(self)
    
    calc_shortest_path(self)
    calc_disjoint_path(self)
    print(self.paths)

    for room in self.rooms.values():
        print(room, room.route)
    
    for link in self.links:
        print(link)


if __name__ == '__main__':
    fn = '1.txt'
    import sys
    if (len(sys.argv) == 2):
        fn = sys.argv[1]
    app = App(fn)
    app_calc(app)
