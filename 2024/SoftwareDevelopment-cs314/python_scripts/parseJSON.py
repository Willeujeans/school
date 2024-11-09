import os
import sys
import json

#python parseJSON.py Vincenty output.json

def get_json_data(directory):
    list_of_data = []
    for filename in os.listdir(directory):
        if filename.endswith('.json'):
            file_path = os.path.join(directory, filename)
            with open(file_path, 'r') as file:
                try:
                    data = json.load(file)
                    list_of_data.append(data)
                except json.JSONDecodeError as e:
                    print(f"Error decoding JSON from {filename}: {e}")
    return list_of_data


def write_to_file(filePath, data):
    with open(filePath, 'w') as json_file:
        json.dump(data, json_file, indent = 4) 


def main():
    if len(sys.argv) != 3:
        print("only accepts 2 additional arguments")
        return
    input_directory = sys.argv[1]
    output_file = sys.argv[2]
    data = get_json_data(input_directory)
    keys: set = set()
    for dictionary in data:
        for key in dictionary.keys():
            keys.add(key)
    keys_as_list = list(keys)
    for i in range(len(keys_as_list)):
        print(i, keys_as_list[i])
    user_input = input("enter keys seperated by spaces: ")
    user_input_list = user_input.split(" ")
    for dictionary in data:
        for each in user_input_list:
            dictionary.pop(keys_as_list[int(each)])
    print(data)
    write_to_file(output_file, data)


if __name__ == "__main__":
    main()