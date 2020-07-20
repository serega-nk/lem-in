

# ENUM LinkType
LINK_EDGE = 0
LINK_ZERO = 1
LINK_NONE = 2
LINK_REVERSE = 3
LINK_SPLIT = 4
LINK_DIRECTED = 22


class Room:
    def __init__(self, name):
        self.name = name
        # split room
        self.flag = False
        self.split = None
        # link, shortest path algorithm Bellman-Ford
        self.link = None
        self.level = 0

    def __repr__(self):
        if self.flag:
            return f'Room("{self.name}, F")'
        return f'Room("{self.name}")'

class Link:
    def __init__(self, room1, room2):
        self.room1 = room1
        self.room2 = room2
        self.type = LINK_EDGE

    def __repr__(self):
        type_name = ("LINK_EDGE", "LINK_ZERO", "LINK_NONE", "LINK_REVERSE", "LINK_SPLIT")[self.type]
        return f'Link ({type_name}, {self.room1}, {self.room2})'

class App:
    def __init__(self, fn):
        self.rooms = {}
        self.links = []
        self._load(fn)
        assert (self.number > 0)
        assert (self.room_start)
        assert (self.room_end)

    def _add_room(self, name, flag_start, flag_end):
        room = Room(name)
        self.rooms[name] = room
        if flag_start:
            self.room_start = room
        if flag_end:
            self.room_end = room
        
        # split room
        split_name = "[out] " + name
        split_room = Room(split_name)
        self.rooms[split_name] = split_room
        room.split = split_room
        # zero link
        link = Link(room.split, room)
        link.type = LINK_ZERO
        self.links.append(link)
        # print(link)


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


def calc_bellman_ford(self, debug=False):
    
    def calc_bellman_ford_clean():
        for room in self.rooms.values():
            room.link = None
            room.level = 0

    def calc_bellman_ford_update(link, room1, room2, weight):
        # if debug and "[out] 7" in (room1.name, room2.name):
        #     print("DEBUG", room1, room2, "weight", weight, room1.link)

        if room1.link:


            level = room1.level + weight
            if debug:
                print("DEBUG", room1, room2, "weight", weight, "level", level)
            if room2.link is None or room2.level > level:
                if debug:
                    print("update")
                room2.link = link
                room2.level = level
                return 1
        return 0

    calc_bellman_ford_clean()
    # open start room
    self.room_start.link = True

    index = 0
    while (index < len(self.links)):
        count = 0
        for link in self.links:


            if link.type == LINK_EDGE:

                room1 = link.room1.split if link.room1.flag else link.room1
                room2 = link.room2.split if link.room2.flag else link.room2

                count += calc_bellman_ford_update(link, room1, link.room2, 1)
                count += calc_bellman_ford_update(link, room2, link.room1, 1)

            elif link.type == LINK_ZERO:
                count += calc_bellman_ford_update(link, link.room1, link.room2, 0)
    
            elif link.type == LINK_REVERSE:
                count += calc_bellman_ford_update(link, link.room2, link.room1.split, -1)

        if count == 0:
            break
        index += 1

    # 
    print('index', index)
    print(self.room_end.link)
    assert(self.room_end.link)
    print("====")

def calc_suurballe(self, debug=False):

    walk = self.room_end
    while walk != self.room_start:

        link = walk.link

        print(walk, "\t", link)

        if link.type == LINK_EDGE:

            # swap room for link direction
            if link.room1 == walk:
                link.room1, link.room2 = link.room2, link.room1            
            
            if link.room1.flag:
                walk = link.room1.split
            else:
                link.type = LINK_REVERSE
                if link.room1 not in (self.room_start, self.room_end):
                    link.room1.flag = True
                walk = link.room1
            
        elif link.type == LINK_ZERO:

            print("LINK_ZERO")
            walk = link.room1

        elif link.type == LINK_REVERSE:
            
            link.type = LINK_NONE
            link.room1.flag = False
            # print("!!!!!!!!!!\t", link)
            print("LINK_REVERSE", link)
            walk = link.room2

        elif link.type == LINK_NONE:
            raise Exception("LINK_NONE")


    print("====")

def app_calc(self):

    calc_bellman_ford(self)
    calc_suurballe(self)

    calc_bellman_ford(self)
    calc_suurballe(self)

    # calc_bellman_ford(self)
 
    # for room in self.rooms.values():
    #     if room.link:
    #         print(room, room.link)

    # calc_suurballe(self)

    print("=======")

    for link in self.links:
        if link.type == LINK_EDGE:
            
            room1 = link.room1.split if link.room1.flag else link.room1
            room2 = link.room2.split if link.room2.flag else link.room2
            print(room1.name, '->', link.room2.name, '==', 1)
            print(room2.name, '->', link.room1.name, '==', 1)
            pass
        elif link.type == LINK_REVERSE:
            print(link.room2.name, '->', link.room1.split.name, '==', -1)
            pass
        elif link.type == LINK_ZERO:
            #print(link)
            pass
        elif link.type == LINK_NONE:
            print(link)
            pass
        else:
            print(link)

if __name__ == '__main__':
    fn = '1.txt'
    import sys
    if (len(sys.argv) == 2):
        fn = sys.argv[1]
    app = App(fn)
    app_calc(app)
