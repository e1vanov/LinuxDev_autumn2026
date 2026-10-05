Name:		myshow
Version:	0.0.1
Release:	alt1
Group:		Other
License:	Unlicense
URL:		https://github.com/e1vanov/LinuxDev_autumn2026/tree/main/01_TerminalProject
Source:		%name-%version.tar.gz
Summary:	My show pkg

%description
Minimal program to show files

%prep
%setup

%build
make 

%install
make install DESTDIR=%buildroot BINDIR=%_bindir

%files
%_bindir/%name
