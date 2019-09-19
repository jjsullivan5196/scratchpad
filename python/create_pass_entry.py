#!/usr/bin/python
import sys
import tldextract

from subprocess import run

subargs = { 'text': True, 'capture_output': True }

def get_pass_paths():
    paths = run(['find', sys.argv[1], '-type', 'f'], **subargs).stdout.splitlines()
    paths_fixed = [p.replace('.gpg', '') for p in paths]

    return paths_fixed

def get_pass_info(path):
    info = {}
    info_text = run(['pass', 'show', path], **subargs).stdout.splitlines()

    info['pass'] = info_text[0]

    for line in info_text[1:]:
        (key, value) = line.split(':', 1)
        info[key.strip()] = value.strip()

    if not 'login' in info or not info['login']:
        info['login'] = 'default'

    tld = tldextract.extract(info['url'])
    info['tld'] = f'{tld.domain}.{tld.suffix}'

    return info

def save_pass(info):
    run(['pass', 'insert', '-m', f'{info["tld"]}/{info["login"]}'], encoding='utf8', input=info['pass'])

paths = get_pass_paths()

for p in paths:
    print(f'Path: {p}')
    info = get_pass_info(p)
    save_pass(info)
