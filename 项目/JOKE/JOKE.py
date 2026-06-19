import requests
import json
def main():
	url = "https://api.apiopen.top/getJoke"
	r = requests.post(url,data={"type":"text"},headers= {})
	joke_list = r.json().get("result")
	while True:
		i = 0;
		for joke_item in joke_list:
			print(joke_item.get("text")+"\n")
			i = i + 1
			if input("%d/20"%(i))=="q":
				return
if name=='main':
	main()