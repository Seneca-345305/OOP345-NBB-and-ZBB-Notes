#ifndef SENECA_UnPTR_H
#define SENECA_UnPTR_H
namespace seneca {
   template <typename Type>
   class UnPtr {
      Type* m_ptr{};
   public:
      UnPtr( Type* ptr ) :m_ptr{ ptr } { }
      UnPtr( const UnPtr& ) = delete;
      UnPtr& operator=( const UnPtr& ) = delete;
      UnPtr( UnPtr&& up )noexcept {
         m_ptr = up.m_ptr;
         up.m_ptr = nullptr;
      }
      UnPtr& operator=( UnPtr&& up )noexcept {
         if ( this != &up ) {
            delete m_ptr;
            m_ptr = up.m_ptr;
            up.m_ptr = nullptr;
         }
         return *this;
      }
      Type& operator*( ) {
         return *m_ptr;
      }
      Type* operator->( ) {
         return m_ptr;
      }
      operator const void* ()const {
         return static_cast<const void*>(m_ptr);
      }
      virtual ~UnPtr(){
         delete m_ptr;
      }
   };
}
#endif // !SENECA_UTPR_H
