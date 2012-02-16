def puts_i(s)
  print "\t"
  puts s
end

@input_files = ARGV

puts "# include <stdio.h>"
puts

@input_files.each do |f|
  puts "# include \"#{f}\""
end
puts

puts "int main(int argc, char **argv)"
puts "{"

@input_files.each do |f|
  current_struct = nil

  puts_i "// #{f}"

  File.open(f, 'r').each_line do |l|
    if l =~ /^typedef struct ([a-zA-Z0-9_]*)$/
      current_struct = $1
      puts_i "printf(\"#{current_struct}:\\n\");"
    elsif l =~ /^\t.* \**(.*);/ and not current_struct.nil?
      puts_i "printf(\"\\t.#{$1}: equ %lu\\n\", offsetof(#{current_struct}, #{$1}));"
    elsif l =~ /} (.*);/ and not current_struct.nil?
      puts_i "printf(\"\\t.struct_size: equ %lu\\n\\n\", sizeof(#{current_struct}));"
      puts
      current_struct = nil
    end
  end

  puts
end

puts_i "return 0;"
puts "}"
