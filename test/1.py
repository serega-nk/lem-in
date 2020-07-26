
def load(fn):
    rooms = {}
    links = []
    ants = {}
    
    def add_room(name, route):
        rooms[name] = route
    
    def add_link(name1, name2):
        links.append((name1, name2,))

    iterble = open(fn)
    _ = int(next(iterble))
    route = 0
    for line in iterble:
        line = line.strip()
        if line.startswith('L'):
            for a, b in map(lambda a: a[1:].split('-'), line.split(' ')):
                if a not in ants:
                    ants[a] = []
                ants[a].append(b)
        elif line.startswith('#'):
            if line == '##start':
                route = -1
            if line == '##end':
                route = -2
        elif ' ' in line:
            name = line.split(' ')[0]
            add_room(name, route)
            route = 0
        elif '-' in line:
            add_link(*line.split('-'))    
    
    route = 0
    uniq = set()
    for _, names in ants.items():
        key = '->'.join(names)
        if key not in uniq:
            route += 1
            for name in names[:-1]:
                rooms[name] = route
            uniq.add(key)
    
    import random
    colors = ['red', 'green', '#cccccc',] + 
        ['#' + ''.join([random.choice('0123456789ABCDEF') for j in range(6)]) for i in range(route)]

    def get_color(route):
        if route == -1:
            return 'red'
        elif route == -2:
            return 'green'
        elif route == 0:
            return '#cccccc'
        else:
            return colors[route - 1]

    route1, route2 = rooms[name1], rooms[name2]
    route = max(route1, route2)
    if route1 == route2:
        route = route1
    elif route1 < 0:
        route = route2
    elif route2 < 0:
        route = route1
    else:
        route = 0

    return rooms, links

import matplotlib.pyplot as plt
import networkx as nx

rooms, links = load('9.txt')

G = nx.Graph()

# nodes
for name, color in rooms.items():
    G.add_node(name, color=color)

# edges
for name1, name2, color in links:
    G.add_edge(name1, name2, color=color)

# colors
node_color = [data['color'] for _, data in G.nodes(data=True)]
edge_color = [data['color'] for _, _, data in G.edges(data=True)]

# positions for all nodes
pos = nx.spring_layout(G)  

# nodes
nx.draw_networkx_nodes(G, pos, node_size=100, node_color=node_color)
# edges
nx.draw_networkx_edges(G, pos, width=1, edge_color=edge_color)

#
plt.axis("off")
plt.show()
