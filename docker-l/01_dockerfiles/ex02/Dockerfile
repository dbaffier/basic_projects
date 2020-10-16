# Build process #
# docker build -t ft-rails .

FROM ruby:2.5.1

RUN apt-get update -qq && apt-get install -y nodejs && gem install rails && gem install bundler

ONBUILD COPY . /opt/app
ONBUILD WORKDIR /opt/app

ONBUILD RUN bundle install --jobs 20 --retry 5
ONBUILD EXPOSE 3000
ONBUILD RUN rake db:migrate
ONBUILD RUN rake db:seed
