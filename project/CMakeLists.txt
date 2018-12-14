cmake_minimum_required(VERSION 3.12)
project(project)

set(CMAKE_CXX_STANDARD 14)

add_executable(project main.cpp Game.cpp Player.cpp ArrayLib.cpp PlayerNode.cpp PlayerQueue.cpp MatchMakerRevised.cpp MatchMakerRevised.h MatchMaker.cpp MatchMaker.h)
