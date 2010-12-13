kt-msgpack
==========
MessagePack-RPC Server Plugin for Kyoto Tycoon


## Requirements

Following programs are requred to build:

  - gcc >= 4.1 with C++ support
  - [MessagePack for C++](http://msgpack.org/) >= 0.5.2
  - [mpio](http://github.com/frsyuki/mpio) >= 0.3.5
  - [MessagePack-RPC for C++](http://msgpack.org/) >= 0.3.0
  - [Kyoto Tycoon](http://fallabs.com/kyototycoon/)


## Installation

Configure and install in the usual way:

    $ ./bootstrap  # if needed
    $ ./configure
    $ make
    $ sudo make install


## Example

    $ ktserver -plsv /usr/local/lib/libktmsgpack.so -plex 'port=18801'


## License

    Copyright (C) 2010 FURUHASHI Sadayuki
    
       Licensed under the Apache License, Version 2.0 (the "License");
       you may not use this file except in compliance with the License.
       You may obtain a copy of the License at
    
           http://www.apache.org/licenses/LICENSE-2.0
    
       Unless required by applicable law or agreed to in writing, software
       distributed under the License is distributed on an "AS IS" BASIS,
       WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
       See the License for the specific language governing permissions and
       limitations under the License.

See also NOTICE file.

