import sys
import os

# python uploadBinary.py <tag> [extra ...]
if __name__ == '__main__':
    args = sys.argv

    # Check if the executor provided the right length of arguments
    if len(args) < 2:
        print('Please use: python uploadBinary.py <tag> [extra ...]')
        exit(1)

    # read the release tag of the arguments
    tag = args[1]

    # defining all remaining arguments as one string
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
    extra = extra[:len(extra)-1] # remove last space character

    # publish the release to github. Exit with the return code of the publish command
    exit(os.system(f'gh release create {tag} {extra} build/cli'))