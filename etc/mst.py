import networkx as nx
import sys
import math
import matplotlib.pyplot as plt

M_PI = 3.14159265358979323846
earthRadiusKm=6371.0

def deg2rad(deg):
    return (deg * M_PI / 180)

def distanceEarthKm(lat1d, lon1d, lat2d, lon2d):
    lat1r = deg2rad(lat1d)
    lon1r = deg2rad(lon1d)
    lat2r = deg2rad(lat2d)
    lon2r = deg2rad(lon2d)
    u = math.sin((lat2r-lat1r)/2)
    v = math.sin((lon2r-lon1r)/2)
    return int( 2.0 * earthRadiusKm * math.asin(math.sqrt(u*u+math.cos(lat1r)*math.cos(lat2r)*v*v)))

with open(sys.argv[1], 'r') as fhandle:
    content = fhandle.readlines()
content = [ list(map(float, x.strip().split(' '))) for x in content][1:]

### Criação do grafo
G = nx.Graph()
G.add_nodes_from(list(range(0,len(content))))

for node_u in range(0,len(content)):
    for node_v in range(0,len(content)):
        if not node_u == node_v:
            d = distanceEarthKm(content[node_u][0], content[node_u][1], content[node_v][0], content[node_v][1])
            G.add_weighted_edges_from([(node_u, node_v, d)])

# Calculo MST
MST = nx.minimum_spanning_tree(G)

# Pega o Edge mais custoso
print(sorted(MST.edges(data=True),key= lambda x: x[2]['weight'],reverse=True)[0][2]['weight'])

# da plot no grafo
pos=nx.spring_layout(MST)
labels = nx.get_edge_attributes(MST,'weight')
nx.draw(MST,pos)
nx.draw_networkx_edge_labels(MST, pos, edge_labels=labels)
plt.show()

