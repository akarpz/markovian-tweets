$LOAD_PATH.unshift File.join(File.dirname(__FILE__), '..', 'lib')

require 'rubygems'
require_relative 'chatterbot/dsl'
require_relative 'chatterbot'

use_streaming

replies do |tweet|
 # Any time you put the #USER# token in a tweet, Chatterbot will
 # replace it with the handle of the user you are interacting with
 src = tweet.text
#  TODO: pass the output of the tweet to a method that calls the python code 
#  -> c++ code -> returns the tweet then tweet it
 puts src
 
#  reply "Yes #USER#, here's an impression", tweet
end



