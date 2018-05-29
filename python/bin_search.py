def search(data, value):
    print(data)
    if not data:
        return False
    assert(type(data[0]) == type(value))
    mid = (len(data)-1) // 2
    print(mid)
    if value == data[mid]:
        return True
    elif value > data[mid]:
        search(data[mid+1:], value)
    elif value < data[mid]:
        search(data[:mid], value)

def binary_search_recursive(a_list, item):
    """Performs recursive binary search of an integer in a given, sorted, list.
    a_list -- sorted list of integers
    item -- integer you are searching for the position of
    """

    first = 0
    last = len(a_list) - 1

    if len(a_list) == 0:
        return '{item} was not found in the list'.format(item=item)
    else:
        i = (first + last) // 2
        if item == a_list[i]:
            return '{item} found'.format(item=item)
        else:
            if a_list[i] < item:
                return binary_search_recursive(a_list[i+1:], item)
            else:
                return binary_search_recursive(a_list[:i], item)

if __name__ == '__main__':
    a = [2, 3, 4, 5, 6, 7, 8, 9]
    z = binary_search_recursive(a, 4)
    x = binary_search_recursive(a, 6)
    print(z)
    print(x)
    print(search(a, 4))
