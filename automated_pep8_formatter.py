from requests import get
import json
from subprocess import call
from os import listdir, walk, getcwd


class Repositories:

    def __init__(self, URL):
        self.repos = [elem['full_name'] for elem in get(URL).json()]

    def get_repos(self):
        return self.repos

    @staticmethod
    def get_repos_from_url_from_file(filename):
        with open(filename) as f:
            jsoned = json.load(f)
            return [elem['full_name'] for elem in get(jsoned['URL']).json()]


def clone(repo_name):
    call(['git', 'clone', 'git@github.com:' + repo_name + '.git'])


def fix_python_files():
    full_files = []
    working_dir = getcwd()
    res = walk('.')
    dirs = [elem for elem in next(res)[1] if elem[0] != '.']
    for curr_dir in dirs:
        full_files.extend(get_full_file_paths(curr_dir))
    for curr_file in full_files:
        call(['autopep8', '--in-place', '--aggressive',
              '--aggressive', '--max-line-length', '78', curr_file])
        call(['pep8', curr_file])


def get_full_file_paths(curr_dir):
    file_paths = []
    working_dir = getcwd()
    top = walk(curr_dir)
    for root, dirs, files in top:
        for fle in files:
            if fle[-3:] == '.py':
                file_paths.append(working_dir + '/' + root + '/' + fle)
    return file_paths

if __name__ == '__main__':
    result = Repositories.get_repos_from_url_from_file('settings.json')
    for res in result:
        clone(res)
    fix_python_files()
