# **GitHub checking || gernerate SSH key**
```
Username for 'https://github.com': NotSurprised
Password for 'https://NotSurprised@github.com': 
```

```
ls -al ~/.ssh

ssh-keygen -t rsa -b 4096 -C "roro8016489@gmail.com_"

eval "$(ssh-agent -s)"

ssh-add ~/.ssh/id_rsa

sudo apt-get install xclip

xclip -sel clip < ~/.ssh/id_rsa.pub
```

```
sudo apt install ruby

sudo apt-get install ruby-dev

sudo gem install ffi -v '1.9.23'

gem install jekyll bundler

git clone https://github.com/security-onigiri/blog

cd blog

bundle install

bundle exec jekyll serve

```