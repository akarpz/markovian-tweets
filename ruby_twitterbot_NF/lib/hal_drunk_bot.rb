#!/usr/bin/env ruby

$LOAD_PATH.unshift File.join(File.dirname(__FILE__), '..', 'lib')

require 'rubygems'
require_relative 'chatterbot/dsl'
require_relative 'chatterbot'




    fileName = "../qued_tweets.txt"
    halTweets = File.open(fileName, "r")
    text = halTweets.read
    halTweets.close

    tweetQue = text.split(" |||| ")
    
p = ["asdasdfasdf"]
tweet(p[0])




# tweet "9000 series is the most reliable computer has ever made a mistake or distorted information. We are all, by any practical definition"

