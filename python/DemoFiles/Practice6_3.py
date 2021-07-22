dictionary = {
    'var':'Variable', 
    'list':'Array in python', 
    'tuple':"I'm not very sure what it is but it's kinda strange thing", 
    'dictionary': "You're map, right?", 
    'for': 'For loop , haha'
    }

dictionary["list.append(element)"] = 'Add element to the list'
dictionary["list.remove(element)"] = 'Remove element from the list.'
dictionary["list.pop(index)"] =  "Remove the elment in the index from the list and return it."
dictionary["list.reverse()"] = "Reverse the list."
dictionary["list.sort()"] = "Irreversably sort the list."

for k, v in dictionary.items():
    print(k + ':' + v)

print("\n")

riversAndNations = {
    'nile': 'egypt', 
    'chang jiang': 'china', 
    'rhein': 'the united kindom'
}

for k, v in riversAndNations.items():
    print("The " + k.title() +
        " runs through " +
        v.title() + '.')

print('\n')

favorite_langrages = {
    'jen': 'python', 
    'sarah': 'c', 
    'edward': 'ruby', 
    'phil': 'python'
}

respondents = ['jen', 'sarah', 'edward', 'phil', 'harvey', 'tiffany']

for res in respondents:
    if res not in favorite_langrages.keys():
        print("Hi, %s, we sincerely invite you to join the survey!" %res.title())
    elif res in favorite_langrages.keys():
        print("Hi, %s, thanks for your response!" %res.title())
