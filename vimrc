
call plug#begin()
	Plug 'dracula/vim', { 'as': 'dracula' }
	Plug 'vim-airline/vim-airline'
	Plug 'vim-airline/vim-airline-themes'
	Plug 'tpope/vim-commentary'
	Plug 'phanviet/vim-monokai-pro'
call plug#end()

" Filetype
filetype on
filetype plugin on
filetype indent on

" Disable mouse
set mouse=

" Set UI
set number
syntax on
set termguicolors
colorscheme monokai_pro
set cursorline
set ttyfast
set autoindent

" Search
set hlsearch
set incsearch
set showmatch
set ignorecase

" Airling theme
let g:airline_theme='base16_monokai'

" Font
set guifont=Iosevka:h15
set backspace=indent,eol,start
set encoding=UTF-8

" Syntax
setlocal tabstop=4
setlocal shiftwidth=4

" Keys mapping
map <S-j> 10j
map <S-k> 10k

" Disable swap file
set noswapfile
