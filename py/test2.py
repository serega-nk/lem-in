
class RoomType:
	room_start = 1
	room_end = 2
	room_one = 3
	room_in = 4
	room_out = 5

class Room:
	def __init__(self, name, room_type=RoomType.room_one):
		self.type = room_type
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
		self.routes = []
		self.rooms = {}
		self.links = []
		self._load(fn)
		assert (self.number > 0)
		assert (self.room_start)
		assert (self.room_end)
		self.room_start.type = RoomType.room_start
		self.room_end.type = RoomType.room_end

def route_get(self):
	route = []
	walk = self.room_end
	while walk:
		route.insert(0, walk)
		if (walk == self.room_start):
			return route
		walk = walk.path
	return None

def algo_pre(self):
	def pre_remove(point):
		for link in point.links.values():
			link_room = link.room2
			for name in point.links.keys():
				if name in link_room.links:
					#print("algo_pre remove", link_room.links[name])
					self.links.remove(link_room.links[name])
					del link_room.links[name]
	pre_remove(self.room_start)
	pre_remove(self.room_end)

def algo_bellman_ford(self):
	def algo_clean(self):
		for room in self.rooms.values():
			room.level = 0
			room.path = None
	
	algo_clean(self)
	self.room_start.path = True
	#
	flag = True
	index, count = 0, len(self.links)
	while flag and index < count:
		flag = False
		for link in self.links:
			if link.room1.path:
				value = link.room1.level + link.weight
				if not link.room2.path or (value < link.room2.level):
					link.room2.level = value
					link.room2.path = link.room1
					flag = True
		index += 1
	#print(index)
	#for room in self.rooms.values():
	#	print(room.name, room.level, room.path)

def print_routes(self):
	
	for walk in self.routes:
		route = []
		route.insert(0, self.room_end)
		while walk:
			if walk.type != RoomType.room_out:
				route.insert(0, walk)
			walk = walk.route
		print(route)


def algo_suurballe(self):
	
	def remove_link(self, room1, room2):
		if room2.name in room1.links:
			link = room1.links[room2.name]
			del room1.links[room2.name]
			self.links.remove(link)

	def split_room(self, room):
		room.type = RoomType.room_in
		room_out = Room(room.name + '_out', RoomType.room_out)
		self.rooms[room_out.name] = room_out
		for name, link in room.links.items():
			link.room1 = room_out
			room_out.links[name] = link
		room.links.clear()
		return room_out

	def append_link(self, room1, room2, weight):
		link = Link(room1, room2)
		link.weight = weight
		room1.links[room2.name] = link
		self.links.append(link)

	walk = self.room_end
	if not walk.path:
		return

	self.routes.append(walk.path)
	while walk and walk.path:
		room = walk.path
		
		remove_link(self, walk, room)
		remove_link(self, room, walk)

		if room.type == RoomType.room_one:			
			room_out = split_room(self, room)
			append_link(self, walk, room_out, -1)
			append_link(self, room_out, room, 0)
			#route
			room.route = None
			room_out.route = room
			walk.route = room_out
		elif room.type == RoomType.room_in:
			pass
		else:
			walk.route = room
		
		walk = walk.path
		if (walk == self.room_start):
			break


def algo_routes(self):
	routes = []
	for walk in self.routes:
		route = []
		route.insert(0, self.room_end)
		while walk:
			if walk.type != RoomType.room_out:
				route.insert(0, walk)
			walk = walk.route
		routes.append(route)
	return routes
	


def get_info_routes(routes):
	longest_length = 0
	total_length = 0
	number_routes = len(routes)
	for route in routes:
		route_length = len(route) - 1
		longest_length = max(longest_length, route_length)
		total_length += route_length
	info_routes = {
		'longest_length': longest_length,
		'total_length': total_length,
		'number_routes': number_routes,
	}
	return info_routes

def solve(self):

	algo_pre(self)

	possible_count = min(len(self.room_start.links), len(self.room_end.links))
	
	number = 5
	info = None

	routes = []
	count = 0

	while True:
		algo_bellman_ford(self)
		algo_suurballe(self)		
		if self.room_end.path is None:
			break
		
		#print("routes =", count, "({})".format(value))
		
		new_routes = algo_routes(self)
		new_info = get_info_routes(new_routes)
		effective = 0
		if info:
			effective = new_info['longest_length'] * info['number_routes'] - info['total_length'] + info['number_routes']
		new_effective = new_info['longest_length'] * new_info['number_routes'] - new_info['total_length'] + new_info['number_routes']
		if number <= effective:
			break
	
		routes = new_routes
		info = new_info
		count += 1

		if effective >= new_effective:
			break

		if count == possible_count:
			print("possible_count")
			break

	for route in routes:
		print(route)


if __name__ == '__main__':
	fn = '1.txt'
	import sys
	if (len(sys.argv) == 2):
		fn = sys.argv[1]
	res = AntFarm(fn)
	solve(res)
