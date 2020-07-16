
class Room:
	def __init__(self, name):
		self.name = name
		self.links = {}
		self.level = 0
		self.path = None
		self.route = None
	
	def __repr__(self):
		return f'Room("{self.name}")'
	


class Link:
	def __init__(self, room1, room2):
		self.room1 = room1
		self.room2 = room2
		self.weight = 1

	def __repr__(self):
		return f'Link({self.room1}, {self.room2}, weight={self.weight})'

class AntFarm:
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
		link1 = Link(room1, room2)
		link2 = Link(room2, room1)
		room1.links[name2] = link1
		room2.links[name1] = link2
		self.links.append(link1)
		self.links.append(link2)

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

	def __init__(self, fn):
		self.rooms = {}
		self.links = []
		self._load(fn)
		assert (self.number > 0)
		assert (self.room_start)
		assert (self.room_end)

def algo_clean(self):
	for room in self.rooms.values():
		room.level = 0
		room.path = None

def route_get(self):
	route = []
	walk = self.room_end
	while walk:
		route.insert(0, walk)
		if (walk == self.room_start):
			return route
		walk = walk.path
	return None


def algo_bfs_priority(self):
	
	def gen_id(save=[0,]):
		save[0]	+= 1
		return save[0]
	
	import heapq
	
	queue = []
	heapq.heappush(queue, (1, gen_id(), self.room_start))
	while (queue):
		level, _, room = heapq.heappop(queue)
		for link in room.links.values():
			link_room = link.room2
			if link_room != self.room_start and (link_room.path is None or link_room.level > level):
				link_room.level = level
				link_room.path = room
				heapq.heappush(queue, (level + 1, gen_id(), link_room))


def algo_bhandari_step2(self):
	walk = self.room_end
	while walk and walk.path:
		# комната откуда пришли
		room = walk.path
		# 
		if room.name in walk.links:
			link = walk.links[room.name]
			self.links.remove(link)
			del walk.links[room.name]
			#
			if walk not in (self.room_start, self.room_end):
				walk.route = room
				print("ROUTE ", walk, room)
		# 
		if walk.name in room.links:
			link = room.links[walk.name]
			self.links.remove(link)
			del room.links[walk.name]
		#
		walk = walk.path
		if (walk == self.room_start):
			break


def solve(self):
	algo_clean(self)
	algo_bfs_priority(self)
	algo_bhandari_step2(self)

	# for link in self.links:
	# 	print(link)


if __name__ == '__main__':
	fn = '1.txt'
	import sys
	if (len(sys.argv) == 2):
		fn = sys.argv[1]
	res = AntFarm(fn)
	solve(res)
