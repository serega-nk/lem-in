
PART_OUT = 1
PART_IN = 0

class Room_Type:
    normal_type = 0
    start_type = 1
    end_type = 2

#here we init type of links
#part1 (out) ---> part2 (in)
#also this class actual for inner links of part1 (in) ---> part2 (out), with weight = 0
class Link:
    def __init__(self, part1, part2, weight):
        self.part1 = part1
        self.part2 = part2
        self.link_weight = weight
    
    def __repr__(self):
        return f'LINK ({self.part1} -> {self.part2} ==== {self.link_weight}) \n'
    # def __repr__(self):
    #     # return f'part1 ===== ({self.part1}) , part2 ===== ({self.part2}) \n'
    #     return '\n'
#Here we init the parts, parts can be inner & external
class Part:
    def __init__(self, type_of_part, room):
        self.room = room
        self.part_type = type_of_part
        self.cost = 100000000 #hwo in me?? allien 100% IT IS ALLOW US understand where we haVE TO GO
    
    def __repr__(self):
        # return f'part_of_room = ({self.part_type})'
        name = ('[IN]', '[OUT]')[self.part_type]
        return f'{name}{self.room}'

class Room:
    def __init__(self, name):
        self.name = name
        self.part_out = Part(PART_OUT, self)
        self.part_in = Part(PART_IN, self)
        self.path = 0
    
    def __repr__(self):
        return f' ROOM ({ self.name})'
    # def __repr__(self):
        # return f'ROOM_NAME = ({ self.name}),||||| PART_IN = { self.part_in} , PART_OUT =  { self.part_out}||||||||||||'

###THE MOST IMPORTANT PART THE CALCULATIONS OF ROOMS
def belman_ford():
    app.rooms['S'].part_out.cost = 0
    # print(app.rooms['S'].part_out.cost)
    n = len(app.links)
    for link in range(1, n):
        link.part_in < link.part_out
    # while (app.links)
    # print(app.links)

def app_calc(self):
    belman_ford()


class App:
    #thank you dear Sergey!!
    def __init__(self, fn):
        self.links = []
        self.rooms = {} #we can call the room throo the room_name
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

if __name__ == '__main__':
    fn = '1.txt'
    import sys
    if (len(sys.argv) == 2):
        fn = sys.argv[1]
    app = App(fn)
    app_calc(app)
