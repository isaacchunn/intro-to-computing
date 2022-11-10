# import time

# def stopwatch(seconds):
#     start = time.time()
#     elapsed = 0
#     while elapsed < seconds:
#         elapsed = time.time() - start
#         print("Elapsed: {}".format(elapsed))
#         time.sleep(0.998)

# stopwatch(20)

a,b = 10,20
a,b,c = a+b, a*b, a/b
print(a,b,c)

