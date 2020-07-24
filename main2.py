

PART_IN = 0
PART_OUT = 1

class Part:
    def __init__(self, _type, room):
        self.type = _type
        self.room = room
        # bellman ford
        self.link = None
        self.level = 0

    def __repr__(self):
        name = ('[IN]', '[OUT]')[self.type]
        return f'{name}{self.room}'

class Room:
    def __init__(self, name):
        self.name = name
        self.part_in = Part(PART_IN, self)
        self.part_out = Part(PART_OUT, self)
        self.path = None
    
    def __repr__(self):
        return f'{self.name}'

class Link:
    def __init__(self, part1, part2, weight):
        self.part1 = part1
        self.part2 = part2
        self.weight = weight
   
    def __repr__(self):
        return f'LINK ({self.part1} -> {self.part2} = {self.weight})'


def bellman_ford(self):
    # clean
    for room in self.rooms.values():
        room.part_out.link = None
        room.part_out.level = 0
        room.part_in.link = None
        room.part_in.level = 0
    # open    
    self.room_start.part_out.link = True
    # 
    index = 0
    while True:
        update = False
        for link in self.links:
            if link.part1.link:
                level = link.part1.level + link.weight
                if link.part2.link is None or link.part2.level > level:
                    link.part2.link = link
                    link.part2.level = level
                    update = True
        if not update:
            break
        if index == len(self.links):
            raise Exception("WHILE -1")
    return self.room_end.part_in.link is not None
    ###


def suurballe(self, debug=False):
    walk = self.room_end.part_in.link
    while walk != True:
        # if debug:
        #     print(walk)
        
        
        link = walk.part1.link

        #print(walk)

        if walk.weight == -1:
            #print('REMOVE', walk)
            self.links.remove(walk)
        else:
            #if walk.part2.type == PART_IN and walk.part1.type == PART_OUT and walk.part2.room != walk.part1.room:
            if walk.part2.room != walk.part1.room:
                assert (walk.part2.type == PART_IN and walk.part1.type == PART_OUT)
                room1 = walk.part2.room
                room2 = walk.part1.room
                room1.path = room2
                #print('###', walk, room1, room2)

            walk.part1, walk.part2 = walk.part2, walk.part1
            walk.weight = -walk.weight

        walk = link

    self.paths.append(self.room_end.path)
    #

def make_routes(self):
    routes = []
    for walk in self.paths:
        route = []
        route.insert(0, self.room_end)
        while walk:
            route.insert(0, walk)
            walk = walk.path
        routes.append(route)
    return routes


# def print_test1(routes):
    
#     line = ' '.join(str(len(route) - 1)  for route in routes)
#     print(len(routes), ' ( ', line, ')', sep='')

def print_test1(self, routes):
    
    rooms = set()
    for route in routes:
        for room in route[1:-1]:
            assert (room not in rooms)
            rooms.add(room)
    
    routes = [len(route) - 2 for route in routes]
    count = self.number
    value = 0
    while (count > 0): 
        count -= 1
        routes[0] += 1
        value = max(value, routes[0])
        routes = sorted(routes)
    print(len(routes), '=', value, '/', self.required)
    return value


def app_calc(self):
    last = 0
    index = 0
    save = []
    routes = []
    while bellman_ford(self):
        suurballe(self)
        routes = make_routes(self)
        value = print_test1(self, routes)
        index += 1
        if last and last < value:
            break
        last = value
        save = routes


    for route in save:
        print(route)
    
    # for link in self.links:
    #     print(link)


class App:
    def __init__(self, fn):
        self.required = 0
        self.rooms = {}
        self.links = []
        self._load(fn)
        assert (self.number > 0)
        assert (self.room_start)
        assert (self.room_end)
        self.paths = []
    
    def _add_room(self, name, flag_start, flag_end):
        assert (name not in self.rooms)
        room = Room(name)
        self.rooms[name] = room
        if flag_start:
            self.room_start = room
        elif flag_end:
            self.room_end = room
        else:
            link = Link(room.part_in, room.part_out, 0)
            self.links.append(link)

    def _add_link(self, name1, name2):
        room1 = self.rooms[name1]
        room2 = self.rooms[name2]        
        link = Link(room1.part_out, room2.part_in, 1)
        self.links.append(link)
        link = Link(room2.part_out, room1.part_in, 1)
        self.links.append(link)

    def _load(self, fn):
        iterble = open(fn)
        self.number = int(next(iterble))
        flag_start = flag_end = False
        for line in iterble:
            line = line.strip()
            if line.startswith('#Here is the number of lines required: '):
                self.required = int(line.split(': ')[1])
            elif line.startswith('#'):
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

if __name__ == '__main__':
    fn = '99.txt'
    import sys
    if (len(sys.argv) == 2):
        fn = sys.argv[1]
    app = App(fn)
    app_calc(app)
