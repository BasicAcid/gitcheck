# gitcheck

Look for unstaged/uncommited changes in multiple git repos.

I tend to work on several repos at the same time, this gives me
a way to quickly check their status.

At the moment it is just a loop that descend directories, check if
there is a .git, and if yes then run "git status -s" on it.

It does not go deeper than the first git repo, so it's not usable for
submodules.

## Example

Here is an example output:
```bash
➜  ~ gitcheck
===== /home/david/Workspace/programming/Haskell/metadoctor =====
 M dist-newstyle/cache/config
 M metadoctor.cabal
 M package.yaml
 M src/Lib.hs
 M stack.yaml
 M stack.yaml.lock
?? dist-newstyle/cache/elaborated-plan
?? dist-newstyle/cache/improved-plan
?? dist-newstyle/cache/plan.json
?? dist-newstyle/cache/solver-plan
?? dist-newstyle/cache/source-hashes
?? dist-newstyle/sdist/
===== /home/david/Workspace/programming/C/gitcheck =====
 M README.md
 M gitcheck.c
?? .#README.md
 ```
