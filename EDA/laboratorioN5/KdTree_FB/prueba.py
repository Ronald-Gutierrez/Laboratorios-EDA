import csv
import math
import time

class Distance:
     def _init_(self, dis, vec):
        self.d = dis  
        self.point = vec

def distance(a, b):
        res = 0
        for i in range(len(a)):
            res += (a[i] - b[i]) ** 2
        res = math.sqrt(res)
        return res

def k_nearest_neighbor(k, target, points_list):
    dist_list = []
    for i in points_list:
        dist_list.append(Distance(distance(target,i), i))
    dist_list.sort(key=lambda x: x.d)
    ret_list = []
    for i in range(k):
        ret_list.append(dist_list[i].point)
    return ret_list
        
if _name_ == "_main_":
    points_list = []
    
    f = open("results.txt","w")
    f.write("n/k 1 2 3 4 5 6 7 8 9 10\n")
    with open('1000.csv', 'r') as file:
        points_list = []
        f.write("1000 ")
        reader = csv.reader(file)
        ins_start = time.time()
        
        for row in reader:
            points_list.append([int(row[0]),int(row[1]),int(row[2])])
        
        ins_end = time.time()
        
        ins_time = ins_end - ins_start
        
        
        for i in range(10):
            knn_start = time.time()
            all_neighbors = k_nearest_neighbor(i + 1, [300,300,300], points_list)
            knn_end = time.time()

            knn_time = knn_end - knn_start
            f.write(str(knn_time) + ' ')

        f.write('\n')