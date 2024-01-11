# gitcheck

Look for unstaged/uncommited changes in multiple git repos.

I tend to work on several repos at the same time, this gives me
a way to quickly check their status.

At the moment it is just a loop that descend directories, check if
there is a .git, and if yes then run "git status -s" on it.

It does not go deeper than the first git repo, so it's not usable for
submodules.
