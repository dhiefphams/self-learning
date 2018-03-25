# Module is a way to share methods accross class
module Human
	attr_accessor :name, :height, :weight
	def run
		puts self.name + " runs"
	end
end
