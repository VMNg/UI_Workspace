# UI_Workspace
git config --global user.name "Your name"

git config --global user.email "email@.com"

mkdir ~/Documents/workspace/UI_Workspace

cd ~/Documents/workspace/UI_Workspace

ls -al ~/.ssh
ssh-keygen -t rsa -b 4096 -C "email@gmail.com"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa
cat ~/.ssh/id_rsa.pub
=> copy bỏ vào Add SSH 

git clone git@github.com:VMNg/UI_Workspace.git


