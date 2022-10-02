//
// Created by Basam on 2/10/2022.
//

#ifndef GANG_OF_FOUR_DESIGN_PATTERNS_APIWRAPPER_H
#define GANG_OF_FOUR_DESIGN_PATTERNS_APIWRAPPER_H

namespace StructuralPatterns {
    namespace Adapter {
        class ApiWrapper {
        public:
            virtual ~ApiWrapper();
            virtual void call() = 0;
        };

        class LegacyApi {
        public:
            LegacyApi();
        };

        class AdapterApi : public ApiWrapper, private LegacyApi {
        public:
            AdapterApi();
            void call() override;
        };

    } // StructuralPatterns
} // Adapter

#endif //GANG_OF_FOUR_DESIGN_PATTERNS_APIWRAPPER_H
