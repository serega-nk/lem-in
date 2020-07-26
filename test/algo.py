
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
        self.remove = False
        self.pair = None
   
    def __repr__(self):
        return f'LINK ({self.part1} -> {self.part2} = {self.weight})'



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
        #else:
        link = Link(room.part_in, room.part_out, 0)
        self.links.append(link)

    def _add_link(self, name1, name2):
        room1 = self.rooms[name1]
        room2 = self.rooms[name2]        
        link1 = Link(room1.part_out, room2.part_in, 1)
        self.links.append(link1)
        link2 = Link(room2.part_out, room1.part_in, 1)
        self.links.append(link2)
        link1.pair = link2
        link2.pair = link1

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
