1. Language 
   1. C++
2. Why 
   1. Interest in Language Features 
      1. In the Computer Science department at Westmont College, computer science courses tend to focus on abstractions
      such as algorithms, data structures, and programming paradigms. Most classes are taught in high level languages
      like Python and Java, and low or systems level languages do not often receive the spotlight.
      In this environment, we would like to explore some of the unique facets that a systems level,
      imperative, and object oriented programming language like C++ can provide. We are curious how increased control
      over hardware architecture can shape the way we write code, as well as how that code runs
      (whether this relates to speed, difficulty of the compilation/linking process, or more). 
   2. Interest in Industry Use 
      1. Furthermore, C++ has for many years held a significant position in the backbone of software development, and
      we are both interested in learning this language better for the purpose of understanding its widespread adoption
      as well as for the enrichment of our resumes and skill sets when it comes to industry standards.
   3. What Program
      1. Our program will be an implementation of Turner Whitted’s Recursive Ray Tracing algorithm invented in 1980,
      the very first algorithm which introduced recursion to previous ray tracing techniques.
      This algorithm greatly improved the realism provided by ray tracing and laid the groundwork for all modern ray
      tracing techniques. 
      2. The base of our project will be to produce a program that can read in data representing a scene with basic
      geometric three dimensional objects and a lightsource (format undecided) and will write to an image file
      (format undecided) to give a visual representation of that scene. 
      3. While the complete scope of this project is yet to be determined, we expect that it is possible to be extended
      in the following ways:
         1. Object Material Composition - Different materials interact with light differently via interactions such as 
         shadows, reflections, and refractions. We expect our project to include at minimum shadows and reflections,
         but refractions might be something that we can add later on. An even further thought to consider might be
         objects with variable refractivity - similar to how the atmospheres of planets can vary in composition at
         different altitudes,
         adding different effects to light traveling through different regions of an atmosphere. 
         2. Light Source Composition/Position/Quantity - Another way this project could be extended would be through
         manipulation of light sources, whether that includes color, intensity, temperature, placement, quantity light
         sources, or more. 
         3. If we seriously have too much time, we could always look into parallel computation.
3. Justification
   1. Showcasing C++ features 
      1. C++ has speed as a main concern, which is perfect for this computation heavy and traditionally time-consuming
      task. To get a better overhead look at its speed, it would be necessary to compare it to a language which does
      not have the same low level features.
      To do this, we might have to build our own parallel implementation in a language like Python,
      since no one really purposefully makes such computation heavy applications in languages not designed for it.
      It probably wouldn’t even make sense to compare our program to most other publicly available ray tracing
      libraries, since those will likely be optimized for gpu parallelization and clever mathematical reductions in
      workload. Unfortunately, we are not currently aware of any other way to showcase the features of C++.
   2. Feasibility
      1. Our project may be time consuming in nature, but it should not be impossible. 
      Ray-tracing is a well trodden path, and there are plenty of materials to help understand the concept behind it 
      (here’s a decent slideshow I found in about five minutes). Implementation hopefully should follow smoothly.
