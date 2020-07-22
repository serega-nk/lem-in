
LINK_EDGE = 0
LINK_REVERSE = 1
LINK_ZERO = 2
LINK_NONE = 3


class Link:
    def __init__(self, _type, room1, room2):
        self.type = _type
        self.room1 = room1
        self.room2 = room2
    
    # def get_key(self):
    #     return f'{self.type} {self.room1.name} {self.room2.name}'


class Room:
    def __init__(self, name):
        self.name = name


class App:
    def __init__(self):
        self.links = []

    # def add_link(self, link):
    #     self.links[link.get_key()] = link
    #     pass
