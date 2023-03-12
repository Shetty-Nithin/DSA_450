// // JS is Synchronous and single threaded.

const { writeFileSync, readFile } = require("fs");
const { resolve } = require("path");

// // Node.js by Ryan Dahl

// // Node js is an environment to run js outside of the browser. 
// // Created in 2009 and built on top of the chrome's v8 engine.

// // Diff between browser js and node.js
// // (No access to browser api in node.js such as geolocation, fetch etc...)
// //         Browser                    Node.js
// //     __________________          __________________
// //         DOM                        No DOM
// //         Window                     No Window
// //         Interactive Apps           Server-side Apps
// //         No Filesystems             Filesystems
// //         Fragmentation              Versions
// //         ES6 Modules                CommonJS

// // GLOBAL - No window
// // _dirname  - path to current directory
// // _filename - file name
// // require   - function to use modules (commonJS)
// // module    - info about current module (file)
// // process   - info about env where the program is being executed

// // Node uses CommonJS library under the hood
// // CommonJS, every is file is module by default
// // Modules - Encapsulated code (only share minimum)

// console.log(module)


// // how to export
// module.exports = {property1, property2}
// // OR
// const person = {
//     name : "nithin shetty",
// }
// module.exports.person = person

// // how to import
// const properties = require("./location/of/the/module")
// console.log(module.exports);



// // Note: If we have a function inside one module(different file)
// // and if we require this file in other module(other file) like
// // "require("./location/firstModule")", then also the function inside the first
// // module will run.
// // Or in another words, when we import a module, it invoke the module.

// // Built-in modules: OS, PATH, FS, HTTP, etc...
// // OS : 
    // const os = require('os');
    // console.log(os.userInfo()); // info about the current user
    // cnosole.log(os.uptime)// method returns the system uptime in seconds
    // console.log(os.type(), os.release(), os.totalmem(), os.freemem());

// // PATH : 
    // const path = require('path');
    // const filePath = path.join('\content', 'subfolder', 'test.txt'); // example
    // console.log(path.sep, path.join(), path.basename(filepath));

// // FS : 
    // // 1. Asynchronuosly - non-blocking
    // // 2. Synchronuosly - blocking

    // // Synchronuos
    // const {readFileSync, writeFileSync} = require('fs');
    // const firstFile = readFileSync('./test.txt', 'utf8');
    // const secondFile = readFileSync('./test2.txt', 'utf8');
    // console.log(firstFile);
    // console.log(secondFile);

    // writeFileSync('./test3.txt', 'hello this is the 3rd line of the third file.',  {flag: 'a'});
    // const thirdFile = readFileSync('./test3.txt', 'utf8');
    // console.log(thirdFile);

    // // Asynchronuos - callback hell
    // const {readFile, writeFile, write} = require('fs');
    // readFile('./test.txt', 'utf8', (err, result) => {
    //     if(err){
    //         console.log(err);
    //         return;
    //     }
    //     const frist = result;
    //     readFile('./test2.txt', 'utf8', (err, result) => {
    //         if(err){
    //             console.log(err);
    //             return;
    //         }
    //         const second = result;
    //         writeFile('./test4.txt', 'this is the 4th file.', (err, result) => {
    //             if(err){
    //                 console.log(err);
    //                 return;
    //             }
    //             console.log(result);
    //         });
    //     })
    // })
    
// // HTTP : 
    // const http = require('http'); // http is built-in node module
    // const server = http.createServer((req, res) => {
    //     if(req.url === '/'){
    //         res.end('welcome to home page.');
    //     }
    //     else if(req.url === '/about'){
    //         res.end('this is your about page');
    //     }
    //     else res.end('no such page exists');
    // });
    // server.listen(5000);


    // const { readFile } = require('fs')
    // readFile('./test.txt', 'utf8', (err, result) => {
    //     if(err) console.log(err);
    //     else console.log(result);
    // })

    // //-----------------------------
    // // Promise (When it completes, its results are stored in the promise and can then be ‘claimed’ by the caller.)
    // const getText = (path) => {
    //     return new Promise((resolve, reject) => {
    //         readFile(path, 'utf8', (err, result) => {
    //             if(err) reject(err);
    //             else resolve(result);
    //         })
    //     })
    // }

    // getText('./test.txt')
    //     .then(result => (console.log(result)))
    //     .catch(err => console.log(err));

    
    // //--------------------
    // // Async Await (Async/Await — Making Promises Look Like Synchronous Code and Improving Performance.)
    // const getText2 = (path) => {
    //     return new Promise((resolve, reject) => {
    //         readFile(path, 'utf8', (err, result) => {
    //             if(err) reject(err);
    //             else resolve(result);
    //         })
    //     })
    // }

    // const start = async() => {
    //     try {
    //         const first = await getText2('./test.txt');
    //         const second = await getText2('./test2.txt');
    //         console.log(first);
    //         console.log(second);
    //     } catch (error) {
    //         console.log(error);
    //     }
    // }
    // start();


    // //Instead of wiriting the proimse on read and write explicitely we can make use of the inbuilt
    // //"util.promisify()".
    // const { readFile, writeFile } = require('fs')
    // const util = require('util');
    // const readFilePromise = util.promisify(readFile);
    // const writeFilePromise = util.promisify(writeFile);

    // const start2 = async() => {
    //     try {
    //         const first = await readFilePromise('./test.txt', 'utf8');
    //         const second = await readFilePromise('./test2.txt', 'utf8');
    //         await writeFilePromise('./test5.txt', 'this is 5th file');
    //         const third = await readFilePromise('./test5.txt', 'utf8');
    //         console.log(first);
    //         console.log(second);
    //         console.log(third);
    //     } catch (error) {
    //         console.log(error);
    //     }
    // }
    // start2();



// EVENTS :
    // Event-driven programmings are used heavily in Node.js

    // on -> listen for an event
    // emit -> emits an event

    // const EventEmitter = require('events');
    // const customEmitter = new EventEmitter();

    // customEmitter.on('response', (name) => {
    //     console.log('data received from : ', name);
    // });
    // customEmitter.on('response', () => {
    //     console.log('another data received');
    // });
    // customEmitter.emit('response', 'nithin shetty');

    // const http = require('http');
    // const server = http.createServer();
    
    // // we can subscribe to it/ listen to it/ and responds to it
    // server.on('request', (req, res) => {
    //     res.end('welcome');
    // })
    // server.listen(5000);

    /*
    const events = require('events');
    const eventEmitter = new events.EventEmitter();
    
    // Handler associated with the event
    const connectHandler = function connected() {
        console.log('Connection established.');
        // Trigger the corresponding event
        eventEmitter.emit('data_received');
    }
    
    // Binds the event with handler
    eventEmitter.on('connection', connectHandler);
    
    // Binds the data received
    eventEmitter.on(
        'data_received', function () {
            console.log('Data Transfer Successful.');
        });
    
    // Trigger the connection event
    eventEmitter.emit('connection');
    
    console.log("Finish");
    // Many of Node’s built-in modules inherit from EventEmitter.
    */

// STREAMS : 
    // * Writeable
    // * Readable
    // * Duplex
    // * Transform

    // const { createReadStream } = require('fs');
    // const stream = createReadStream('./nodenotes.js', { encoding : 'utf8'});
    
    // stream.on('data', (result) => {
    //     console.log(result);
    // });
    // stream.on('error', (err) => {
    //     console.log(err);
    // })
    
    // // by default the size of the buffer is 64kb, however we can control the size
    // // by using 
    // // highWaterMark - Control Size
    // // last buffer - remainder
    // // const stream = createReadStream('./test.txt', {highWaterMark : 90000});
    // // const stream = createReadStream('./test.txt', {encoding : 'utf8'});


// Exchange of data on the web (HTTP Messages) : 
    // - user send the http req message and then the server sends 
    //   the http res message.

    // Aim of server to make the resource available to the user.

    // HTTP Methods : GET, POST, PUT, DELETE
    // Structure of a Request Message : 
        // method -> GET /contact http/1.1
        // Headers
        // Body(optional)
    // Structure of a Response Message : 
        // http/1.1 200 OK
        // Headers
        // Body(optional)
        // Headers : Content-Type: text/html; charset=UTF-8
        //           Content-Type: application/json; charset=utf-8


        
// Server using express.js
    // const express = require('express');
    // const app = express();

    // app.get('/', (req, res) => {
    //     res.send('sup')
    // });

    // app.all('*', (req, res) => {
    //     res.status(404).send('all methods');
    // })

    // app.listen(5000, () => { console.log('server is up')});

// API vs SSR
    // API - JSON  SSR - TEMPLATE
    // SEND
    // RES.JSON()  RES.RENDER()

// app.use(express.static('./public'));


//_______________________________
// INTERVIEW QUESTIONS ON NODE.JS
//_______________________________

/*
1. What is Node.js?
    * Very popular scripting language that is primarily used for server
    side scripting requirements.
    * It has numerous benefits compared to other server-side programming
    languages out there, the most noteworthy one being the NON-BLOKCING I/O.

2. Diff between Node.js and JS/
    Factor        Node.js                    JS
    * Engine      V8-Google Chrome           V8, Spider Monkey, and JS Core
    * Usage       To perform non-blocking    For general client-side
                  activities                 operations.
    * Working     Interpreter-Scripting      Programming Languages

3. Can you briefly explaing the working of Node.js?
    * Node.js is an entity that runs in a virtual environment, using JS as the 
    primary scripting language.
    * It uses a simple V8 environment to run on, which helps in the provision
    of feature like the non-blocking I/O and single-threaded event loop.

4. Where is Node.js used?
    Node.js is used in a variety of domains. But, it is very well regarded
    in the design of the following concepts:
    * Network application
    * Distributed computing
    * Responsive web apps
    * Server-Client applications

5. What is the difference between Node.js and Angular?
            Node.js                             Angular
    * Used in the situations where      * Best fit for the development of 
    scalability is a requirement        real-time applications
    * Ability to generate queries in a  * Ability to simplify an application
    database                            into the MVC architecture.
    * Mainly used to develop small/     * Mainly used to develop real-time
    medium-sized applications           interactive web applications
    * Provides many frameworks such     * Angular is an all-in-one web app
    as Sails, Partial, and Express      framework
    * Coded using C++ and JS            * Coded in Typescript.

6. Why is Node.js is single-threaded?
    * Node.js works on the single-threaded model to ensure that there is 
    support for asynchronous processing.
    * With this, it makes it scalable and efficient for applications to
    provide high performance and efficiency under high amount of load.

7. What are the different API functions supported by Node.js?
    There are type of API functions:
        * Asynchronous APIs: Used for non-blocking functions
        * Synchronous APIs: Used for blocking functions.

8. What is the difference between synchronous and asynchronous functions?
    Synchronous:
     * Synchronous functions are mainly used for I/O operations.  
     * They are instantaneous in providing a response to the data movement
     in the server and keep up with the data as per the requirement.
     * If there are no responses, then the API will throw an error.

     Asynchronous:
     * As the name suggests, asynchronous is works on the basis of not being 
     synchronous.
     * Here, HTTP requests when pushed will not wait for the response to begin.
     Responses to any previous requests will be continous even if the server
     has already got the response.

    (Node extends the idea of IO operations,IO operations in node is non-blocking,
    it does not wait for the network operation to complete instead it registers
    a callback to the event loop,and pass control back to node, so that your 
    code can run when the data has been read.)
 
9. What is the meaning of the control flow function?
    * The control flow function is the common code snippet, which executes
    whenever there are any asynchronous function calls made.
    * They are used to evaluate the order in which these functions are executed
    in node.js
    (it is the order in which computer executes the script)

10. Why is node.js so popular these days?
    Node.js has gained an immense amount of traction as it mainly uses JS.
    It provides programmers with the following options:
    * Writing js on the server.
    * Access to the HTTP stack
    * File I/O entities
    * TCP and other protocols
    * Direct DB access

11. What is event loop in the Node.js?
    * When running an application, callbacks are the entities that has to
    be handled. In the case of node.js event loops are used for this purpose.
    Since node.js supports the non-blocking send, this is the very important
    feature to have.
    * The working of the event loop begins with the occurence of the callback,
    whenever an event begins. This is usually run by a specific listner.
    Node.js will keep executing the code after the functions have been called,
    without expecting the output prior to the beginning.
    * Once, all of the code is executed, outputs are obtained and the callback
    function is executed.
    * This works in the form of a continous loop, hence the name event loop.

12. What are the asynchronous tasks that should occure in an event loop?
    Following are some of the tasks that can be done using an event loop
    asynchronously:
    * Blocking send requests
    * High computational requirement
    * Real time I/O operations

13. What is the order of execution in the control flow statement?
    The following is the order in which control flow statements are
    used to process function calls:
    * Handling execution and queue
    * Data collection and storage
    * Concurrency handling and limiting
    * Execution of the next piece of code

14. What are the input arguments for an asynchronous queue?
    There are 2 main arguments that an asynchronous queue uses:
    * Task function
    * Concurrency value
    
    npm i async
    const async = require('async')
    const queue = async.queue('function', 'concurrency value')
    // The concurrency value tells the queue, the number of elements to be processed at a particular time.

15. Are there any disadvantages to using Node.js?
    Disadvantages:
        Reduces performance when handling Heavy Computing Tasks
        Node.js invites a lot of code changes due to Unstable API
        Node.js Asynchronous Programming Model makes it difficult to maintain code
        Choose Wisely – Lack of Library Support can Endanger your Code
        High demand with a few Experienced Node.js Developers
        * A multi-threaded platform can run more effectively and provide
        better responsiveness when it comes to the execution of intensive
        CPU computation.
        * Usage of relations DB with node.js is becoming obsolete already.
    Advantages:
        High-performance for Real-time Applications
        Easy Scalability for Modern Applications
        Cost-effective with Fullstack JS
        Community Support to Simplify Development
        Easy to Learn and Quick to Adapt
        Helps in building Cross-functional Teams
        Improves App Response Time and Boosts Performance
        Reduces Time-to-Market of your applications
        Extensibility to Meet Customized Requirements
        Reduces Loading Time by Quick Caching
        Helps in Building Cross-Platform Applications


16. What is the primary reason to use the event-based model in node.js?
    The event-based model in the node.js is used to overcome the problems
    that occurs when using blocking operations in the I/O channel.

17. How can you import external libraries into Node.js?
    External libraries can be easily imported into Node.js using the 
    following command:  var http = require('http');
    This command will ensure that the HTTP library is loaded completely, 
    along with the exported object.

18. What is meant by event-driven programming in Node.js?
    * Event-driven programming is a technique in which the workflow execution
    of a program is mainly controlled by the occurence of events from external
    programs or other sources.
    * The event-driven architecture consits of 2 entities, namely:
        - Event handling
        - Event selection

19. What are the difference between AJAX and Node.js?
            AJAX                            Node.js
    * Client-side programming tech      * Server-side scripting language
    * Executes in the browser           * Executes on the server

20. What are the frameworks that are used majorly in Node.js today?
    * Hapi.js
    * Express.js
    * Sails.js
    * Meteor.js
    * Derby.js
    * Adonis.js

    Express.js provides good scalability, flexibility, and minimalism.

21. What are the security implementations that are present in Node.js?
    Following are the important implementations for security:
    * Error handling protocol
    * Authentication pipelines

22. What is the meaning of a test pyramid?
    * A test pyramid is a methodology that is used to denote the number 
    of test cases that are executed in total.
    * Executed in unit test, integration test, and combined testing(in that order).
    * This maintained to ensure that an ample number of test cases are 
    executed for the end-to-end development of a project.

23. What is libuv?
    * Libuv is a widely used library present in Node.js. It is used to 
    complement the asynchronous I/O functionality of Node.js
    * It was developed in-house and used alongside systems such as 
    Luvit, Julia, and more.
    * Following are some of the features of libuv:
        - File system event handling
        - Child forking and handling
        - Asynchronous UDP and TCP sockets
        - Asynchronous file handling and operations

24. Why does Goolge uses the V8 engine for Node.js?
    * Google makes use of the V8 engine because it can easily converts JS
    into a low-level-language.
    * This is done to provide high performance during the execution of an
    application
    * Also provides user s the real-time abilities to work with the application.

25. What is the difference between spawn and fork methods in Node.js?
    * The spawn() function is used to create a new process and launch it using 
    the command line. What it does is that it creates a node modules on the
    processor. Node.js invokes this method when the child processes return data.
    * The following is the syntax for the spawn() method:
        child_process.spawn(command[,args][,options])
    
    * The fork() method can be considered as an instance of the already existing
    spawn() method. Spawning ensures that there are more than one active
    worker node to handle tasks at any given point of time.
    * The following is the syntax for the fork() method:
        child_process.fork(modulePath[,args][,options])

26. What is the use of a middleware in Node.js?
    * A middleware is a simple function that has ability to handle incoming
    requests and outbound response objects.
    * Middleware is used primarily for the following tasks:
        - Execution of code(of any type)
        - Updation of request and response objects
        - Completion of request-response iterations
        - Calling the next middleware
    (The main purpose of the middleware is to modify the req and res objects, 
        and then compile and execute any code that is required. It also helps
        to terminate the request-response session and call for the next middleware 
        in the stack.)

27. What are global objects in Node.js?
    * Global objects are the objects with a scope that is accessible across all
    of the modules of the Node.js applcations.
    * There will not be any need to include the objects in every module.
    One of the object is declared as global.
    * Hence this is done to provide any functions, strings, or objects access
    across the applicatoins.

28. Why is assert used in Node.js?
    (The assert module provides a way of testing expressions. If the expression evaluates
        to 0, or false, an assertion failure is being caused, and the program is terminated.)
    * Assert is used to explicitly write test cases to verify the working of a
    piece of code.
    * The following code snippet denotes the usage of  assert:
        var assert = require('assert');
        function add(x, y){
            return x+y;
        }

        var result = add(4, 5);
        assert(result === 9, '4 summed with 5 is 9');
    (if-else is for controlling the flow of your program. assert must not be used for this! Asserts
        are just for having "checkpoints" in your code to check conditions which "should always" match.)

29. What are stubs in Node.js?
    * Stubs are simply functions that are used to assess and analyze individual
    component behavior.
    * When running test cases, stubs are useful in providing the details of 
    the functions executed.

    (A small program routine that substitutes for a longer program which is possible to be loaded
        later or that is remotely located.

        Features of stub:
            Stubs can be either anonymous.
            Stubs can be wrapped into existing functions. When we wrap a stub into the existing 
                function the original function is not called.
            Stubs are functions or programs that affect the behavior of components or modules.
            Stubs are dummy objects for testing.
            Stubs implement a pre-programmed response.)

30. How is test pyramid implemented using the HTML API in Node.js?
    Test pyramids are implemented by defining the HTML API. This is done
    using the following:
        - A higher number of unit test cases
        - A smaller number of integration test methods
        - A fewer number of HTTP endpoint test cases

31. Why is a buffer class used in Node.js?
    * A buffer class is primarily used as a way to store data in Node.js.
    This can be considered as a similar implementation of arrays or lists.
    * Here the class refers to the raw memory location that is not present
    in the V8 heap structure.
    * The buffer class is global, thereby extending its usage across all
    the modules of an application.

32. Why is express.js used?
    * ExpressJS is widely used framework build using Node.js
    * ExpressJS uses management point that controls the flow of data
    between servers and server-side applications.
    * Being lightweight and flexible, ExpressJS provides users with lots of
    features used to design mobile applications.

33. What is the use of the connect module in Node.js?
    * The connect module in Node.js is used to provide communication between
    Node.js an the HTTP module.
    * This also provides easy integration with ExpressJS, using the middleware
    modules.

34. What are streams in Node.js?
    * Streams are a set of data entities in Node.js. These can be considered
    similar to the working of strings and array objects.
    * Streams are used for continous read/write operations across a channel.
    But, if the channel is not available, then all of the data cannot be pushed
    into the memory at once.
    * Hence using stream will make it easy to process a large set of data in a
    continuous manner.
    (Streams are objects that let you read data from a source or write data to
        a destination in continuous fashion.)

35. What are the types of streams available in Node.js?
    There are four fundamental stream types within Node.js:
        Writable: streams to which data can be written (for example, fs.createWriteStream()).
        Readable: streams from which data can be read (for example, fs.createReadStream()).
        Duplex: streams that are both Readable and Writable (for example, net.Socket).
        Transform: Duplex streams that can modify or transform the data as it is written and
                read (for example, zlib.createDeflate()).
        Additionally, this module includes the utility functions stream.pipeline(),
        stream.finished(), stream.Readable.from() and stream.addAbortSignal().

36. What is the use of REPL in Node.js?
    * REPL stands for Read-Eval-Print-Loop.
    * It provides user with a virtual environment to test JS code in Node.js
    * To launch REPL, a simple command called 'node' is used.
    * After this JS commands can be typed directly into command line.

37. What is meant by tracing Node.js?
    * Tracing is a methodology used to collect all of the tracing information
    that gets generated by V8, the node core, and the user space code.
    * All of these will be dumped into a long file and are very useful to
    validate and check the integrity of the information being passed.

38. Where is package.json used in Node.js?
    * The package.json file is a file that contains the metadata about all
    items in a project.
    * It can also be used as a project identifier and deployed as a means to
    handle of the project dependencies.

39. What is the difference between readFile and createReadStream in Node.js?
    readFile:
        * This is used to read all of the content of a given file in an
        asynchronous manner
        * All of the content will be read into the memory before an user can access it.
    createReadStream:
        * This is used to break up the field into smaller chunks and then read it.
        * The default chunk size is 64kb, and this can be changed as per requirement.

40. What is the use of the crypto module in Node.js?
    The crypto module in Node.js is used to provide users the cryptographic
    functionalities.
    This provides them with a large number of wrappers to perform various operations:
    * Cipher
    * Decipher
    * Signing
    * Hashing

41. What is a passport in Node.js?
    * Passport is widely used middleware present in Node.js. It is primarily used
    for authentication, and it can easily fit into any ExpressJS based web applications.
    * With every application created, it will require unique authentication
    mechanisms.
    * This is provided as single modules by using passport, and it becomes
    easy to assign strategies to applications based on requirements, thereby
    avoiding any sort of dependicies.

42. How to get information about the file in Node.js?
    * The fs.stat function is used to get the required information from a file.
    The syntax is as follow:
        fs.stat(path, callback)
    * Where, 
        path is the string that has the path to the name and 
        callabck is the function and 
        stats is an object of fs.stat.

43. How does the DNS lookup function work in Node.js?
    * The DNS loopup method uses the web address for its parameter and 
    return the IPv4 and IPv6 records, correspondingly.
    * There are other parameters such as the options that are ued to set the
    input as an interger or as an object.
    * If nothing is provided here, both IPv4 an IPv6 are considered. The
    third parameter is for the callback function.
    The syntax is : 
        dns.lookup(address, options, callback)
    Example:
        const dns = require('dns');
        dns.lookup('example.org', (err, address, family) => {
            console.log('address: %j family: IPv%s', address, family);
        });

        where :     
            callback: It specifies a function to be called after DNS resolution of the hostnames is done.
            error:  It specifies error if generated. For example ‘ENOTFOUND’ is set if the hostname does not
                    exist or the lookup fails.
            address: It is a string representation of IPv4 and IPv6 addresses.
            family: It is an integer value that specifies the family of the record. The value must be in 
                    4, 6 or 0 where 0 indicates it’s not an IPv4 or IPv6 address. 0 is an indicator of
                    fault in the name resolution service used by the operating system.

44. What is the use of EventEmitter in Node.js?
    * Every single object in Node.js that emits is nothing but an 
    instance of an EventEmitter class.
    * These objects have a function that is used to allow the attchement 
    between the objects and the named events.
    * Synchronous attachements of the functions are done when the EventEmitter
    object emits an event.

45. What is the difference between setImmediate() and setTimeout()?
    * setImmediate() : This function is meant to execute a single script
    once the current event loop is completed.
    * setTimeout() : This function is used to hold a script and schedule it
    to be run after a certain time threshold is over.
    * The order of execution will solely depend on the context in which the
    functions are called. If called from the main module, the timing will be
    based on the performance of the process.

46. What is the use of module.exports in Node.js?
    * The module.exports function is used to expose two functions and bring
    them to a usable context.
    * A module is an entity that is used to store relative code in a single
    snippet.
    * This can be considered as an operation of moving all of the functions
    into one single file.

47. Why do you think you are the right fit for this node.js role?
    * Job description
    * The answer can be elaborated with how your interests align with the 
    technology, job, and the company.

Read More : https://medium.com/capital-one-tech/node-js-control-flow-an-overview-68f76ef750c3
*/
