
class Room:
	def __init__(self, name):
		self.name = name
		self.links = {}
	
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


def route_clear(self):

	for room in self.rooms.values():
		room.path = None
		room.steps = 0


def route_get(self):
	route = []
	walk = self.room_end
	while walk:
		route.insert(0, walk)
		if (walk == self.room_start):
			return route
		walk = walk.path
	return None


def algo_bfs(self):
	queue = []
	queue.append(self.room_start)
	while queue:
		room = queue.pop(0)
		for link in room.links.values():
			if link.room2.path is None:
				link.room2.path = room
				queue.append(link.room2)
	# route = route_get(self)
	# print(route)

def algo_bhandari_step2(self):
	print('route = ', route_get(self))

	walk = self.room_end
	while walk and walk.path:
		room = walk.path
		if room.name in walk.links:
			link = walk.links[room.name]
			link.weight = -2
		link = room.links[walk.name]
		self.links.remove(link)
		del room.links[walk.name]
		walk = walk.path
		if (walk == self.room_start):
			break


def algo_bellman_ford(self):
	self.room_start.path = True
	# print("=====")
	# for room in self.rooms.values():
	# 	if room.path:
	# 		print(f'{room} steps == {room.steps}')
	# print("=====")
	count = 0
	flag = True
	n = len(self.links)
	while flag and count < n:
		count += 1
		# print(count)
		flag = False
		for link in self.links:
			if link.room1.path:
				value = link.room1.steps + link.weight
				if link.room2.path:
					if (value < link.room2.steps):
						link.room2.steps = value
						link.room2.path = link.room1
						flag = True
				else:
					link.room2.steps = value
					link.room2.path = link.room1
					flag = True			
	# print("=====")
	# for room in self.rooms.values():
	# 	if room.path:
			# print(f'{room} steps == {room.steps}')
	# print("=====")

def route_print(self):

	def test(walk):
		route = [self.room_end,]
		while walk:
			route.insert(0, walk)
			if (walk == self.room_start):
				return route
			links = sorted(walk.links.values(), key=lambda x: x.weight)			
			walk = links[0].room2 if links else None
	
	for link in self.room_end.links.values():
		if link.weight == -2:
			route = test(link.room2)
			print(route)
	return None


def algo_pre(self):
	def pre_remove(point):
		for link in point.links.values():
			link_room = link.room2
			for name in point.links.keys():
				if name in link_room.links:
					print("algo_pre remove", link_room.links[name])
					self.links.remove(link_room.links[name])
					del link_room.links[name]
	pre_remove(self.room_start)
	pre_remove(self.room_end)


def solve(self):
	# удаляем связи между дочерними узлами start и end 
	algo_pre(self)

# first way
	route_clear(self)
	algo_bfs(self)

#second way	
	algo_bhandari_step2(self)
	route_clear(self)
	algo_bellman_ford(self)
	algo_bhandari_step2(self)
	#route_print(self)
	route_clear(self)
	algo_bellman_ford(self)
	algo_bhandari_step2(self)
	route_print(self)

#therd way

# #therd way
# 	algo_bhandari_step2(self)
# 	route_clear(self)
# 	algo_bellman_ford(self)

# 	algo_bhandari_step2(self)
# 	route_clear(self)
# 	route_print(self)

	#algo_bhandari_step2(self)
	# for room in self.rooms.values():
	# 	print(room, f'links = {len(self.links)}')
	# for link in self.links:
	# 	print(link)


if __name__ == '__main__':
	fn = '1.txt'
	import sys
	if (len(sys.argv) == 2):
		fn = sys.argv[1]
	res = AntFarm(fn)
	solve(res)
