" Michael's standard settings

" Author: Michael Geddes

" Version: 0.1



" Smart tabbing / autoindenting

set undolevels=100

set nocompatible

set autoindent

set smarttab

" Allow backspace to back over lines

set backspace=2

set exrc

set shiftwidth=4

set tabstop=4

set cino=t0

" I like it writing automatically on swapping

set autowrite

set noshowcmd

if exists('&selection')

  set selection=exclusive

endif


set efm=%*[^\ ]\ %t%n\ %f\ %l:\ %m,%\\s%#%f(%l)\ :\ %t%*[^0-9]%n:\ %m,%*[^\"]\"%f\"%*[^0-9]%l:\ %m,%\\s%#%f(%l)\ :\ %m,%*[^\ ]\ %f\ %l:\ %m,%f:%l:%m,%t%*[^\ ]\ %f\ %l:\ %m,%t%*[^:]:\ \ %f(%l\\,%c):%m,%f:%l:%m,%t%*[^\ ]\ %f\ %l\ %c:\ %m 

"I like things quiet
set visualbell

" Give some room for errors
set cmdheight=2



"Ctags mapping for <alt n> and <alt p>

map <M-n> :cn<cr>z.:cc<CR>

map <M-p> :cp<cr>z.:cc<CR>

set shellpipe=2>&1\|tee

"set shellpipe=\|grep\ -v\ NOTE:\|tee

syntax on


