\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{dokument}

\LoadClassWithOptions{article}

\RequirePackage{polski}
\RequirePackage{xltxtra}

\RequirePackage{xparse}

\PassOptionsToPackage{hyphens}{url}%
\RequirePackage{hyperref}
\hypersetup{
    unicode
}

\RequirePackage{graphicx}
\RequirePackage{pdfpages}
\RequirePackage{caption}
\RequirePackage{subcaption}
\RequirePackage{lastpage}

\RequirePackage{geometry}
\geometry{
  paper=a4paper,
  margin=2.54cm
}

\RequirePackage{fancyhdr}
\fancypagestyle{plain}{%
    \fancyhf{}
    \fancyfoot[C]{Strona \thepage{} z \pageref{LastPage}}
    \renewcommand{\headrulewidth}{0pt}
    \renewcommand{\footrulewidth}{0pt}
}
\pagestyle{plain}

\RequirePackage{setspace}
\onehalfspacing

\defaultfontfeatures{Mapping=tex-text,Scale=MatchLowercase}
%\setromanfont{Charis SIL}
%\setsansfont{Source Sans Pro}
%\setmonofont{Source Code Pro}
\setromanfont{PT Serif}
\setsansfont{PT Sans}
\setmonofont{PT Mono}
%\RenewDocumentCommand {\familydefault} { } {\sfdefault}
\RenewDocumentCommand {\familydefault} { } {\rmdefault}

\RequirePackage[inline]{enumitem}
\RequirePackage[symbol,marginal]{footmisc}

\RequirePackage{listings}
\RequirePackage{xcolor}
\RequirePackage{textcomp}
\definecolor{dkgreen}{rgb}{0.2,0.6,0.2}
\definecolor{gray}{rgb}{0.5,0.5,0.5}
\definecolor{mauve}{rgb}{0.58,0,0.82}
\lstset{
    aboveskip=0.67\baselineskip,
    belowskip=1.0\baselineskip,
    basicstyle=\ttfamily\footnotesize,
    numbers=none,
    numberstyle=\tiny\color{gray},
    %firstnumber=1,
    %stepnumber=5,
    %numbersep=5pt,
    tabsize=4,
    breaklines=true,
    breakatwhitespace=false,
    prebreak = \raisebox{0ex}[0ex][0ex]{\ensuremath{\hookleftarrow}},
    showspaces=false,
    showstringspaces=false,
    showtabs=false,
    frame=,
    captionpos=b,
    numberstyle=\tiny\color{gray},
    keywordstyle=\color{mauve},
    commentstyle=\color{dkgreen},
    stringstyle=\color{mauve}
}

\RequirePackage{dokument-meta}
\RequirePackage{dokument-wersje}
