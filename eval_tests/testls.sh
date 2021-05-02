#!/bin/bash

rm -rf test1 testfile origls minels
mkdir test1
touch testfile
chmod 000 testfile
chmod 000 test1
ls >> origls && ls -a >> origls && ls -l >> origls
ls main.c >> origls && ls -a main.c >> origls && ls -l main.c >> origls
ls libft >> origls && ls -a libft >> origls && ls -l libft >> origls
ls blabla main.c hellostranger incl libft >> origls && ls -a blabla main.c hellostranger incl libft >> origls && ls -l blabla main.c hellostranger incl libft >> origls
ls -r >> origls && ls -t >> origls
ls -r main.c >> origls && ls -t main.c >> origls
ls -r libft >> origls && ls -t libft >> origls
ls -r blabla main.c hellostranger incl libft >> origls && ls - t blabla main.c hellostranger incl libft >> origls
ls -l /var/run/*socket >> origls
ls -R >> origls && ls -R main.c >> origls && ls -R libft >> origls && ls -R *.c >> origls && ls -R blabla main.c hellostranger incl libft >> origls && ls -R /var/run/ >> origls
ls -la -t blabla main.c hellostranger incl libft >> origls && ls -R -a blabla main.c hellostranger incl libft >> origls && ls -r -t -l blabla main.c hellostranger incl libft >> origls
ls -la test1 testfile >> origls

./ft_ls >> minels && ./ft_ls -a >> minels && ./ft_ls -l >> minels
./ft_ls main.c >> minels && ./ft_ls -a main.c >> minels && ./ft_ls -l main.c >> minels
./ft_ls libft >> minels && ./ft_ls -a libft >> minels && ././ft_ls -l libft >> minels
./ft_ls blabla main.c hellostranger incl libft >> minels && ./ft_ls -a blabla main.c hellostranger incl libft >> minels && ./ft_ls -l blabla main.c hellostranger incl libft >> minels
./ft_ls -r >> minels && ./ft_ls -t >> minels
./ft_ls -r main.c >> minels && ./ft_ls -t main.c >> minels
./ft_ls -r libft >> minels && ./ft_ls -t libft >> minels
./ft_ls -r blabla main.c hellostranger incl libft >> minels && ./ft_ls - t blabla main.c hellostranger incl libft >> minels
./ft_ls -l /var/run/*socket >> minels
./ft_ls -R >> minels && ./ft_ls -R main.c >> minels && ./ft_ls -R libft >> minels && ./ft_ls -R *.c >> minels && ./ft_ls -R blabla main.c hellostranger incl libft >> minels && ./ft_ls -R /var/run/ >> minels
./ft_ls -la -t blabla main.c hellostranger incl libft >> minels && ./ft_ls -R -a blabla main.c hellostranger incl libft >> minels && ./ft_ls -r -t -l blabla main.c hellostranger incl libft >> minels
./ft_ls -la test1 testfile >> minels





