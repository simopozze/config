call plug#begin('~/.vim/plugged')
Plug 'jacoborus/tender.vim'
Plug 'arcticicestudio/nord-vim'
Plug 'codota/tabnine-vim'
Plug 'vim-airline/vim-airline'
Plug 'tpope/vim-surround'
Plug 'kyoz/purify', { 'rtp': 'vim' }
Plug 'sheerun/vim-polyglot'
Plug 'preservim/nerdtree'
Plug 'junegunn/goyo.vim'
Plug 'ashisha/image.vim'
call plug#end()

noremap J 10j
noremap K 10k
noremap L 10l
noremap H 10h

noremap F :!pdflatex % && mupdf main.pdf<CR><CR>
set number
set autoindent
set cursorline
syntax on

"set colorcolumn=80
set wildmenu
set encoding=utf-8
filetype plugin indent on
syntax on
set clipboard=unnamed
colorscheme tender
set t_Co=256

"robe
