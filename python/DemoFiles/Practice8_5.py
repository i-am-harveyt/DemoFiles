# 8-12
# def add_ingredients(*add):
#     output = ''
#     for element in add:
#         if element != add[len(add)-1]:
#             output += element + ' '
#         else:
#             output += element
#     print(
#         "This sandwitch has %s." %output
#         )

# add_ingredients('a', 'b', 'c', 'd', 'e')

# 8-13
# def build_profile(first, last, **user_info):
#     """創建一個字典，其中包含我們知道的有關用戶的一切"""
#     profile = {}
#     profile['first_name'] = first
#     profile['last_name'] = last
#     for key, value in user_info.items():
#         profile[key] = value
#     return profile

# harvey = build_profile('harvey', 'tung', height = 181, weight = 75, age = 20)
# print(harvey)

# 8-14
def car_infrom(brand, mod, **information):
    profile = {}
    profile['brand'] = brand
    profile['mod'] = mod
    for k, v in information.items():
        profile[k] = v
    return profile

a = car_infrom('Nissan', 'GTR', year = '?')
print(a)
