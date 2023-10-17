1. Language
        C++
2. Why
        Interest in Language Features
            In the Computer Science department at Westmont College, computer science courses tend to focus on abstractions such as algorithms, data structures, and programming paradigms. Most classes are taught in high level languages like Python and Java, and low or systems level languages do not often receive the spotlight.
            In this environment, we would like to explore some of the unique facets that a systems level, imperative, and object oriented programming language like C++ can provide. We are curious how increased control over hardware architecture can shape the way we write code, as well as how that code runs  (whether this relates to speed, difficulty of the compilation/linking process, or more).
            Interest in Industry Use
            Furthermore, C++ has for many years held a significant position in the backbone of software development, and we are both interested in learning this language better for the purpose of understanding its widespread adoption as well as for the enrichment of our resumes and skill sets when it comes to industry standards.
        What Program
            Our program will be an implementation of Turner Whitted’s Recursive Ray Tracing algorithm invented in 1980, the very first algorithm which introduced recursion to previous ray tracing techniques. This algorithm greatly improved the realism provided by ray tracing and laid the groundwork for all modern ray tracing techniques.
            The base of our project will be to produce a program that can read in data representing a scene with basic geometric three dimensional objects and a lightsource (format undecided) and will write to an image file (format undecided) to give a visual representation of that scene.
            While the complete scope of this project is yet to be determined, we expect that it is possible to be extended in the following ways:
            Object Material Composition - Different materials interact with light differently via interactions such as shadows, reflections, and refractions. We expect our project to include at minimum shadows and reflections, but refractions might be something that we can add later on. An even further thought to consider might be objects with variable refractivity - similar to how the atmospheres of planets can vary in composition at different altitudes, adding different effects to light traveling through different regions of an atmosphere.
            Light Source Composition/Position/Quantity - Another way this project could be extended would be through manipulation of light sources, whether that includes color, intensity, temperature, placement, quantity light sources, or more.
            If we seriously have too much time, we could always look into parallel computation.
3. Justification
        Showcasing C++ features
            C++ has speed as a main concern, which is perfect for this computation heavy and traditionally time consuming task. To get a better overhead look at its speed, it would be necessary to compare it to a language which does not have the same low level features. To do this, we might have to build our own parallel implementation in a language like Python, since no one really purposefully makes such computation heavy applications in languages not designed for it. It probably wouldn’t even make sense to compare our program to most other publicly available ray tracing libraries, since those will likely be optimized for gpu parallelization and clever mathematical reductions in workload. Unfortunately, we are not currently aware of any other way to showcase the features of C++.
Feasibility
            Our project may be time consuming in nature, but it should not be impossible. Ray-tracing is a well trodden path, and there are plenty of materials to help understand the concept behind it (here’s a decent slideshow I found in about five minutes). Implementation hopefully should follow smoothly.






///////////BEGIN OLD PROPOSAL//////////

1. Language:
C++

1.1 Why
We are all interested in getting to know it as it seems to be well adopted in the industry.

2. What Program:
Ray tracing/renderer.

2.1 Justification
Our project will highlight the speed of C++ and its ability to deal well with intense mathematical computation.

There's not much that we have to figure out ourselves in terms of math and so we should be able to spend our time on the actual code.
There's nothing particularly weird about ray tracing - it is a well trodden path that hopefully shouldn't be too hard for us to walk down.
On the other hand, there should be plenty of room to expand the project as necessary, whether that be with a time component and movement,
different and more complex types of material, or more.

///////////END OLD PROPOSAL//////////
