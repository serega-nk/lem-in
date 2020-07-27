#!/usr/bin/env python3

def load():
    rooms = {}
    links = []
    ants = {}
    route = 0
    
    import sys  
    for line in sys.stdin:
        line = line.strip()
        if line.startswith('#'):
            if line == '##start':
                route = 1
            if line == '##end':
                route = 2  
        elif line.startswith('L'):
            for num, name in map(lambda a: a[1:].split('-'), line.split(' ')):
                if num not in ants:
                    ants[num] = []
                ants[num].append(name)
        elif ' ' in line:
            row = line.split(' ')
            if len(row) == 3:
                rooms[row[0]] = route
                route = 0
        elif '-' in line:
            row = line.split('-')
            if len(row) == 2:
                links.append(row)
    #
    route = 2
    uniq = set()
    for _, names in ants.items():
        key = '->'.join(names)
        if key not in uniq:
            route += 1
            for name in names[:-1]:
                rooms[name] = route
        uniq.add(key)
    #
    import random
    colors = ['#cccccc', 'red', 'green',]
    colors += ['#' + ''.join([random.choice('0123456789ABCDEF') for j in range(6)]) for i in range(route)]
    #
    def _link_color(name1, name2):
        route1, route2 = rooms[name1], rooms[name2]
        if route1 == route2:
            route = route1
        elif route1 in (1, 2,):
            route = route2
        elif route2 in (1, 2,):
            route = route1
        else:
            route = 0
        return colors[route]
    #    
    links = [(name1, name2, _link_color(name1, name2),) for name1, name2 in links]
    #
    rooms = [(name, colors[route],) for name, route in rooms.items()]
    #
    return rooms, links


rooms, links = load()

import matplotlib.pyplot as plt
import networkx as nx

G = nx.Graph()

# nodes
for name, color in rooms:
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

# show
plt.axis("off")
plt.show()
