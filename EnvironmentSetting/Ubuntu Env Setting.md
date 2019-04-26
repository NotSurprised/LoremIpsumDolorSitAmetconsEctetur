# Ubuntu Env Setting

### Setting VM with angelboy's config (It will auto update upgrade)
```shell
$wget https://raw.githubusercontent.com/NotSurprised/vimrc/master/install.sh
$sudo ./install.sh
```

### Install Git
```shell
$sudo apt-get install git
```

### Install zshell & oh-my-zsh and configure them
```shell
$sudo apt-get install zsh
$cat /etc/shells
$sh -c "$(wget https://raw.githubusercontent.com/NotSurprised/oh-my-zsh/master/tools/install.sh -O -)"
$chsh -s /bin/zsh
# set zsh to be default shell
$cd ~
$wget https://raw.githubusercontent.com/agnoster/agnoster-zsh-theme/master/agnoster.zsh-theme
$sudo mv Downloads/agnoster.zsh-theme .oh-my-zsh/themes/
$sudo vim .zshrc
# modified ZSH_THEME="robbyrussell" to ZSH_THEME="agnoster"
$sudo apt-get install powerline
$sudo apt-get install fonts-powerline
$sudo -S shutdown -r now
```

### Setting script syntax hightlight plugin
```shell
$git clone https://github.com/zsh-users/zsh-syntax-highlighting.git
$echo "source ${(q-)PWD}/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh" >> ${ZDOTDIR:-$HOME}/.zshrc
$source ~/.zshrc
```

### Setting history recommend:
```shell
$git clone git://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
$vim ~/.zshrc
#add to file bottom
$echo "source $ZSH_CUSTOM/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh" >> ${ZDOTDIR:-$HOME}/.zshrc
$source ~/.zshrc
```

### Change VM login/Lock wallpaper
Change Login wallpaper
```shell
sudo cp Pictures/wallpaper.wiki-Arch-Linux-Wallpaper-Widescreen-PIC-WPC001795.png /usr/share/backgrounds/warty-final-ubuntu.png
```

Change the lock screen wallpaper
```shell
$sudo vim /usr/share/gnome-shell/theme/ubuntu.css
```
Nearly in line 1814:
```css
#lockDialogGroup {
background: #2f3139 url(file:///[fileLocation/filename.png]);
background-repeat: no-repeat;
background-size: cover;
background-position: center;
}
```

