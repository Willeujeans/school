from haversine import haversine, Unit

starting_point = (36.0, 125.0) # (lat, lon)
RKSI = (37.4587, 126.4420)
RKSS = (37.5655, 126.8013)
RKNY = (38.0588, 128.6630)

print(int(haversine(starting_point, RKSI)), haversine(starting_point, RKSS), haversine(starting_point, RKNY))
