# Print something
# print("Your name ? ")
# first_name = gets.to_s
# print("Your last name? ")
# last_name = gets.to_s

# # String concatenation
# print("Hello " + first_name + "" + last_name)
# # Template literal
# print("Welcome #{first_name} #{last_name}\n")


# Object
# Everything is object
print("#{'sss'.class}\n")
puts 1.class

## Constant - variable
ADD_HOME = "/tmp/ss.txt"

=begin
File IO operations
=end
f = File.new(ADD_HOME, "w")
f.puts("Hello file in Ruby")
f.puts("Hello file in Ruby 1")
f.puts("Hello file in Ruby 2")
f.close()

# read data
content = File.read(ADD_HOME)
print(content)

# open each line
File.open(ADD_HOME) do |record|
	record.each do |line|
		# do something	
	end
end

# Load another file
# require("./module")
# or
require_relative "module"
say_hello("Q")

=begin
Control flow
&& || ! and or not
== != ,. <= >=
=end
age = 12
if age < 12
	print("Go to primary school now\n")
elsif (age >= 12) && (age <= 18) # () is optional
	print("Go home and do something\n")
else
	print("Hola\n")
end

unless age > 4
	print("No school\n")
else
	print("Go to school\n")
end
one_line_statement = "Go to school" if age > 12
print(age >= 18 ? "18+\n": "Turn of browser now!\n")

# Switch case
case age
when 12
	print("Hello twelve\n")
when 20
	print("Hello 20\n")
else
	print("No thing\n")
end

# loop
x = 1
# like while
loop do
	x += 1
	# just continue if x is even
	next unless (x % 2) == 0
	puts x

	break if x >= 10
end

while  x <= 20
	x += 1
	next unless x % 3 == 0
	puts x
end

until x >= 40
	x += 1
	next unless x % 3 == 0
	puts x
end

# Array
numbers = [1, 2, 3, 4, 5]
# numbers = Array.new
# numbers = Array.new(5) # 5 spaces
# strs = Array.new(5, "empty") # fill by 'empty' string
arr = [10, 11, 22]
# arr.unshift(0) # push to top
# arr.shift # pop from top
arr.push(100, 200)
arr.pop # pop from end

puts arr.join(", ")

## access
puts numbers[1, 2].join(", ")
puts numbers.values_at(0, 1, 3).join(", ")
numbers.unshift(0)


for n in numbers
	print("#{n} ")
end
puts 
numbers.each do |n|
	print("#{n * 2} ")
end
puts
(0..10).each do |i|
	print("#{i * 2} ")
end
puts

## Function
# pass by value
def add(item1, item2)
	return item1.to_i + item2.to_i
end
puts("2 + 2 = #{add(2, 2)}")

# Exception
begin
	puts(1/0)
rescue Exception => e
	puts(e)
	# exit
end

def check_age(age)
	raise ArgumentError, "Enter positive number" unless age > 0
end

begin
	check_age(-1)
rescue Exception => e
	puts e
end

# Multi lines
multi_str = <<EOM
this is a very long string
aas
aasdfnas d
asdfj asf
asdfja asdf
asdfja #{4 + 5}
EOM
puts multi_str

puts multi_str.include?("string") # can be use for arr
puts multi_str.size
puts multi_str.count("asd") # can be used for arr
puts multi_str.index("asd")
puts multi_str.equal?("aa")
puts multi_str.equal?"aa"
HELLO = "  aaxZZ  "
puts HELLO.upcase
puts HELLO.downcase
puts HELLO.swapcase
puts HELLO.lstrip
puts HELLO.rstrip
puts HELLO.strip
puts "qq".rjust(20, "_")
puts "qq".ljust(20, "_")
puts "qq".center(20, "_")

puts multi_str.chop # pop the last character
puts "aacccc".chomp("ac") # pop the "ac" if it is in the last

puts "xxaaxcasa".delete("a") # delete all a character
puts "cadsf".split(//) # split into characters
puts "welcome a".split(/ /) # into into words seperated by space


## Object
class Animal
	# constructor
	def initialize
		puts "Create the animal"
	end

	def set_name(newname)
		@name = newname
	end

	def getname
		@name
	end

	def name
		@name
	end

	def name=(newname)
		if newname.is_a?(Numeric)
			puts "Name can't be a number"
		else
			@name = newname
		end
	end
end

cat = Animal.new
cat.set_name("Just Q")
puts cat.name
cat.name = "Q ver 2"
puts cat.name


class Dog
	attr_reader :name, :height, :weight
	attr_writer :name, :height, :weight
	# or just one line
	# attr_accessor :name, :height, :weight
	
	def bark
		return "Generic bark"
	end
end

rover = Dog.new
rover.name = "Rover"
puts rover.name

class GermanShepard < Dog
	def bark
		return "Loud bark"
	end
end

max = GermanShepard.new
max.name = "Max"
printf("%s goes %s\n", max.name, max.bark)
# without parentheses
printf "%s goes %s\n", max.name, max.bark

## dictionary
number_hash = {"PI" => 3.14, "Golden" => 1.618, "e" => 2.718}
puts number_hash["PI"]

superheros = Hash["Q", "Superman", "Bruce", "Batman"]
puts superheros["Q"]
superheros["Barry Allen"] = "Flash"
puts superheros["Barry Allen"]

sam_hash = Hash.new("no such key")
puts sam_hash["dog"]
sam_hash["Q"] = "Ironman"

# merge only update the key that is in both hash
# update update the the key doesn't exist the the desination hash
sam_hash.update(superheros)
sam_hash.each do |k, v|
	puts k + " => " + v
end
sam_hash.has_key?("Q")
sam_hash.has_value?("Ironman")
sam_hash.size
sam_hash.empty?

sam_hash.delete("Q")

# Enumerable
class Menu
	include Enumerable

	def each
		yield "Just"
		yield "Give"
		yield "Q"
		yield "A"
		yield "Reason"
	end
end

menu = Menu.new
menu.each do |item|
	puts item
end

puts menu.find{|item| item == "Q" }
puts menu.select {|item| item.size < 3}
puts menu.reject {|item| item.size >= 3}
puts menu.first
puts menu.take(2)
puts menu.drop(2)
puts menu.min
puts menu.max
puts menu.sort
menu.reverse_each{|item| puts item}
