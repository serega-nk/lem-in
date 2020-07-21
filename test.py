

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
        self.path = None
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
        self.delete = False

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


def calc_shortest_path_clean(self):
    for room in self.rooms.values():
        room.save_in.link = None
        room.save_in.level = 0
        room.save_out.link = None
        room.save_out.level = 0

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
            

            
            if link.type == LINK_EDGE:

                def _update(self, save1, save2, link, weight):
                    if save1.link:
                        level = save1.level + weight
                        if not save2.link or save2.level > level:
                            save2.level = level
                            save2.link = link
                            self.update = True
                
                if link.room1.path:
                    _update(self, link.room1.save_out, link.room2.save_in, link, 1)
                else:
                    _update(self, link.room1.save_in, link.room2.save_in, link, 1)

                if link.room2.path:
                    _update(self, link.room2.save_out, link.room1.save_in, link, 1)
                else:
                    _update(self, link.room2.save_in, link.room1.save_in, link, 1)
            
            elif link.type == LINK_REVERSE:

                def _update(self, save1, save2, link, weight):
                    if save1.link:
                        level = save1.level + weight
                        if not save2.link or save2.level > level:
                            save2.level = level
                            save2.link = link
                            self.update = True
                
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

def calc_disjoint_path(self, debug=False):

    link = self.room_end.save_in.link
    room = link.room2 if link.room1 == self.room_end else link.room1
    self.paths.append(room)

    room = self.room_end
    
    while room != self.room_start:
        
        if room.path and room.save_in.link and room.save_out.link and room.save_in.level >= room.save_out.level:
            link = room.save_out.link
        else:
            link = room.save_in.link
        if debug:
            print("#", room, link)

        if link.type == LINK_EDGE:
            
            if link.room2 == room:
                link.room1, link.room2 = link.room2, link.room1
            
            link.type = LINK_REVERSE
            if room not in (self.room_start, self.room_end):
                if room.path and debug:
                    print("PATH", room, room.path)
                room.path = link.room2
                    
                
            room = link.room2            
        
        elif link.type == LINK_REVERSE:
            if debug:
                print("REV", link, link.room1, link.room1.path)
            link.type = LINK_NONE
            link.room1.path = None
            room = link.room1
        else:
            raise Exception("STOP")
    pass


def calc_print(self):
    routes = []
    for walk in self.paths:
        route = []
        route.insert(0, self.room_end)
        while walk:
            route.insert(0, walk)
            walk = walk.path
        routes.append(route)

    # print("=====")
    # for route in routes:
    #     print(" -> ".join(room.name for room in route))
    return routes

def app_calc(self):
    
    
    while calc_shortest_path(self):
        calc_disjoint_path(self)
        routes = calc_print(self)

        s = str(list(sorted(len(route)-1 for route in routes)))
        s = s.replace("[", "( ").replace("]", ")").replace(", ", " ")
        print(len(routes), s)
        # if len(routes) == 10:
        #     for route
        #     print(routes)
        #     break

    # calc_shortest_path_clean(self)
    # for room in self.rooms.values():
    #     print(room, "->", room.path, room.save_in.link, sep="\t")
    # for link in self.links:
    #     print(link)



if __name__ == '__main__':
    fn = '2.txt'
    import sys
    if (len(sys.argv) == 2):
        fn = sys.argv[1]
    app = App(fn)
    app_calc(app)
