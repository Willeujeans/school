def arithmetic_arranger(problems, solve = False):
    if len(problems) > 5:
        return 'Error: Too many problems'
    
    problems_as_list(problems)

    for i in problems:
        for j in i:
            if len(j) > 4:
                return 'Error: Numbers cannot be more than four digits.'
    line_one = ''
    line_two = ''
    line_three = ''
    line_four = ''
    for each in problems:
        add_space_formatting(each)
        add_dashed_line(each)
        line_one += each[0] + ' '
        line_two += each[1] + ' '
        line_three += each[2] + ' '
        line_four += each[3] + ' '
    print('\n'.join([line_one, line_two, line_three, line_four]))
    return problems


def problems_as_list(list: list):
    for i in range(len(list)):
        list[i] = list[i].split(' ')


def add_dashed_line(list: list):
    dashed_line = ''
    dashed_line_size = find_longest_line(list)
    for _ in range(dashed_line_size):
        dashed_line += '-'
    list.append(dashed_line)


def add_space_formatting(problems: list[str]):
    longest_line_size = find_longest_line(problems)
    for i, problem in enumerate(problems):
        character_difference = longest_line_size - len(problems[i])
        new_line = ''
        for _ in range(character_difference):
            new_line += ' '
        new_line += problems[i]
        problems[i] = new_line
        


def find_longest_line(list: list) -> int:
    line_size = 0
    for each in list:
        if len(each) > line_size:
            line_size = len(each)
    return line_size


def is_operator(item: str) -> bool:
    if (len(item) >= 1) and (item == '+' or item == '-'):
        return True
    return False


print(f'\n{arithmetic_arranger(["32 + 698", "3801 - 2", "45 + 43", "123 + 49", "1 + 2 + 3 + 4"])}')