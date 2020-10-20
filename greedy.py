coins = [1,2,5,10,20,50]
price = 17

coins = coins[::-1]
count = 0

i = 0
while price > 0:
	coin = coins[i]

	if price >= coin:
		price -= coin
		count += 1
	else:
		i += 1

	if count > 0 & (price == 0 | price < coin):
		print("use",count,"coin",coin)
		count = 0
