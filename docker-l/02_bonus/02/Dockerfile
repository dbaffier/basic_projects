FROM ubuntu:16.04

RUN apt update
RUN apt install build-essential curl -y
RUN apt install file -y
RUN apt install asciinema -y
RUN apt install unzip -y
RUN apt install emacs24-nox -y
RUN apt install vim -y
RUN apt install nano -y
RUN apt install git -y
RUN apt install libssl-dev -y
RUN apt install zlib1g-dev -y

RUN useradd -ms /bin/bash rust

USER rust
ENV HOME /home/rust
ENV USER rust
ENV SHELL /bin/bash
WORKDIR /home/rust

RUN curl -sSf sh.rustup.rs | sh -s -- -y
RUN echo "export PATH=~/.cargo/bin:$PATH" >> ~/.bashrc
RUN echo "export PS1='\u:\w$ '" >> ~/.bashrc

