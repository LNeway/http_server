cmake_minimum_required (VERSION 2.6)
project (ToooooomServer)
add_executable(ToooooomServer main.cpp 
							Head.hpp		
							NetContext.cpp		
							Request.hpp		
							Response.cpp		
							Const.hpp		
							Log.hpp			
							NetContext.hpp		
							RequestBuild.cpp	
							Response.hpp
							Head.cpp		
							Method.hpp		
							Request.cpp		
							RequestBuild.hpp	
							Utils.hpp)

add_definitions(-std=c++11)