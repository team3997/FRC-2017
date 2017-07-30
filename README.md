# FRC-2017
Development of Team 3997's FRC-2017 Code Base

## Setup
### Forking a repository
#### Fork Repository
Go to https://github.com/team3997/FRC-2017 and click Fork 
Fork to your local account

##### Public key
Follow the steps listed: https://help.github.com/articles/connecting-to-github-with-ssh/ 

##### Run these in git bash:
Go to the directory where you want your clone located
git clone -o team3997 git@github.com:team3997/FRC-2017

#### Add your personal fork
In git bash:
cd FRC-2017
git remote add <GITHUB-USERNAME> git@github.com:<GITHUB-USERNAME>/FRC-2017
git fetch <GITHUB-USERNAME>

##### Remove the push URL from the main fork
This is to prevent accidental pushes to the team3997 fork. Developers should usually work in their personal fork
git remote set-url --push team3997 ""

##### Delete your local copy of master
This is to minimize confusion. Developers should work on separate branches for their features. You will need to be on a branch other than master in order to do this. 
git branch -D master

