import sys
import os

# python uploadBinary.py <tag> [extra ...]

if __name__ == '__main__':
    args = sys.argv
    if len(args) < 2:
        print('Please use: python uploadBinary.py <tag> [extra ...]')
        exit(1)
    tag = args[1]
    extra = ''
    for i in range(3, len(args)):
        flag = args[i]
        if flag == '-F' or flag == '-p':
            extra += args[i] + ' '
        elif args[i-1] == '-F':
            extra += args[i] + ' '
        else:
            print('Unknown argument.')
            exit(1)
    exit(os.system(f'gh release create {tag} {extra} build/cli'))