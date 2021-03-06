/*
Copyright (c) 2015, Wator Vapor
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of wator nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once
#include <fstream>
#include <memory>
using namespace std;
#include "wator/layer.hpp"

namespace Wator {
    class V2CortexLayer :public CortexLayer {
    public:
        /**
         * Constructor
         **/
        explicit V2CortexLayer();
        
        virtual ~V2CortexLayer();

        /**
         * round
         * @return None.
         **/
        virtual void round(void);
        
        /**
         * forward
         * @return None.
         **/
        virtual void forward(void);
     
        /**
         * forward2
         * @return None.
         **/
        virtual void forward2(void);
    protected:
        /**
         * update
         * @return None.
         **/
        virtual void update(void);
    private:
        /**
         * dump to png
         * @return None.
         **/
        void dump(void);
 
        shared_ptr<Blob<bool>> cala(shared_ptr<Blob<bool>> blob);
        
    private:
        const int w_ = 3;
        const int h_ = 3;
        const int sparse_ = 5;
        
        const int iW_ = 8;
        const int iH_ = 8;
        const int iSparse_ = (iW_*iH_)*25/100;
    };

}
