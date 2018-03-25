require_relative "human"
require_relative "smart"

module Animal
	def make_sound
		puts "Grrrrrrrrrrrrr"
	end
end

class Dog
	include Animal
end

rover = Dog.new
rover.make_sound


class Scientist
	include Human
	prepend Smart

	def act_smart
		return "E = mc^2"
	end

end

einstein = Scientist.new
einstein.name = "Albert"
puts einstein.name
puts einstein.act_smart
einstein.run

# Polymorphism
class Bird
	def tweet(bird)
		bird.tweet
	end
end

class Cardinal < Bird
	def tweet
		puts "Cardinal aaaaaaa"
	end
end

class Parrot < Bird
	def tweet
		puts "Squawk"
	end
end

generic_bird = Bird.new
generic_bird.tweet(Cardinal.new)
generic_bird.tweet(Parrot.new)

puts "aasdf,a asdf,".split(",")
