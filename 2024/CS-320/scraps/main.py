from haversine import haversine, Unit

def custom_haversine(coord1, coord2, radius):
    distance = haversine(coord1, coord2, unit=Unit.KILOMETERS) # Default in kilometers
    return (distance * (radius / 6371)) # Adjust with custom radius

coord1 = (35.652832, 139.839478) # Tokyo
coord2 = (-23.5505, -46.6333) # Seattle
radius = 5000 # Custom radius
print(custom_haversine(coord1, coord2, radius))
