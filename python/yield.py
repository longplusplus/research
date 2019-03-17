def consume():
    while True:
        number = yield
        print "consumption start:%d" % (number)


consumer = consume()

next(consumer)

for num in  range(0, 100):
    print "production start:%d" % num
    consumer.send(num)
